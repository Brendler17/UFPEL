"""Fase 2: dada a SENHA, tenta decifrar key_public.en (cripto simetrica) e
detectar a chave publica RSA. Varre cifras/modos/encodings comuns do OpenSSL.
Uso: python decrypt_pubkey.py "<senha>"
Observacao: key_public.en tem 157 bytes (nao multiplo de 16) -> provavel cifra
de FLUXO (rc4, chacha20, aes-*-ctr/cfb/ofb) OU conteudo base64/pem.
"""
import subprocess, sys, os, base64, binascii

SRC = os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "description", "key_public.en")
PWD = sys.argv[1] if len(sys.argv) > 1 else None
if not PWD:
    sys.exit("uso: python decrypt_pubkey.py <senha>")

data = open(SRC, "rb").read()
print(f"key_public.en: {len(data)} bytes")

CIPHERS = ["rc4","rc4-40","aes-256-ctr","aes-128-ctr","aes-256-cfb","aes-128-cfb",
           "aes-256-ofb","aes-128-ofb","aes-256-cbc","aes-128-cbc","aes-192-cbc",
           "aes-256-ecb","aes-128-ecb","des-ede3-cbc","des-cbc","bf-cbc",
           "camellia-256-cbc","chacha20","aria-256-cbc","sm4-cbc","seed-cbc"]
MDS = ["md5","sha256","sha1","sha512"]

def looks_like_key(b):
    if b"-----BEGIN" in b and b"KEY-----" in b:
        return "PEM"
    # DER: SEQUENCE
    if b[:1] == b"\x30" and len(b) > 10:
        return "DER?"
    # base64 de PEM/DER
    try:
        dec = base64.b64decode(b.strip(), validate=False)
        if dec[:1] == b"\x30" or b"BEGIN" in dec:
            return "BASE64"
    except Exception:
        pass
    return None

def try_openssl(cipher, md, salt, pbkdf2):
    cmd = ["openssl","enc","-d","-"+cipher,"-pass","pass:"+PWD,"-md",md]
    if not salt: cmd.append("-nosalt")
    if pbkdf2: cmd.append("-pbkdf2")
    try:
        p = subprocess.run(cmd, input=data, capture_output=True, timeout=10)
        if p.returncode == 0 and p.stdout:
            return p.stdout
    except Exception:
        pass
    return None

# tambem tenta interpretar o arquivo como base64 antes de decifrar
inputs = [("raw", data)]
try:
    b = base64.b64decode(data.strip()); inputs.append(("b64->bin", b))
except Exception: pass

found = []
for label, _ in inputs:
    pass

for cipher in CIPHERS:
    for md in MDS:
        for salt in (False, True):
            for pbk in (False, True):
                out = try_openssl(cipher, md, salt, pbk)
                if out:
                    kind = looks_like_key(out)
                    if kind:
                        print(f"\n>>> POSSIVEL CHAVE  cipher={cipher} md={md} salt={salt} pbkdf2={pbk} fmt={kind}")
                        print(out[:200])
                        found.append((cipher,md,salt,pbk,out))
if not found:
    print("\nNenhuma combinacao openssl produziu algo parecido com chave. "
          "Talvez precise de IV explicito, outra ferramenta, ou o conteudo seja raw DER cifrado em fluxo.")
else:
    print(f"\n{len(found)} candidata(s). Salvando a 1a em pubkey_candidata.bin")
    open("pubkey_candidata.bin","wb").write(found[0][4])
