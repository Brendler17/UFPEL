"""Fase final: dados os primos p,q do modulo RSA, reconstroi a chave privada,
decifra key_for_message.en (RSA) -> chave simetrica, e decifra message.en (openssl enc).
Uso: python finish.py <p> <q>
"""
import sys, subprocess, os

BASE = os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "description")
KFM  = os.path.join(BASE, "key_for_message.en")
MSG  = os.path.join(BASE, "message.en")
# N e e extraidos da chave publica decifrada
N = 0x25bf10833690feff0336fb7f94e895d0f82d02c461f99671e94546abd3a669a3ef8dc278a7e3e6a8b1c2a582cb55251b
E = 65537

def egcd(a, b):
    if b == 0: return (a, 1, 0)
    g, x, y = egcd(b, a % b); return (g, y, x - (a // b) * y)
def inv(a, m):
    g, x, _ = egcd(a, m); return x % m

def main():
    p, q = int(sys.argv[1]), int(sys.argv[2])
    assert p * q == N, "p*q != N"
    phi = (p - 1) * (q - 1)
    d = inv(E, phi)
    c = int.from_bytes(open(KFM, "rb").read(), "big")
    m = pow(c, d, N)
    k = 48  # tamanho do modulo em bytes
    raw = m.to_bytes(k, "big")
    print("RSA plaintext (hex):", raw.hex())
    # tenta remover padding PKCS#1 v1.5 (00 02 PS 00 M) ou mostra cru
    keys_to_try = []
    if raw[0] == 0x00 and raw[1] == 0x02:
        idx = raw.find(b"\x00", 2)
        if idx > 0:
            payload = raw[idx+1:]
            print("PKCS#1 v1.5 -> payload:", payload.hex(), repr(payload))
            keys_to_try.append(("pkcs1", payload))
    # tambem tenta: bytes crus sem zeros a esquerda, e repr ascii
    stripped = raw.lstrip(b"\x00")
    keys_to_try.append(("raw_nolead", stripped))
    keys_to_try.append(("raw_full", raw))
    try:
        print("payload como texto:", stripped.decode("utf-8", "replace"))
    except Exception: pass

    data = open(MSG, "rb").read()
    print("message.en:", len(data), "bytes, header:", data[:8])
    salted = data[:8] == b"Salted__"

    CIPHERS = ["rc4","aes-256-ctr","aes-128-ctr","aes-256-cfb","aes-128-cfb",
               "aes-256-ofb","aes-128-ofb","chacha20","aes-256-cbc","aes-128-cbc",
               "des-ede3-cbc","bf-cbc","camellia-256-cbc"]
    MDS = ["sha256","md5","sha1","sha512"]

    for label, key in keys_to_try:
        # a chave pode ser usada como "senha" (pass:) em texto, ou como bytes hex
        passforms = []
        try:
            txt = key.decode("ascii")
            if txt.isprintable(): passforms.append(("ascii", txt))
        except Exception: pass
        passforms.append(("hex", key.hex()))
        for pflabel, passwd in passforms:
            for cph in CIPHERS:
                for md in MDS:
                    for extra in ([], ["-nosalt"]):
                        cmd = ["openssl","enc","-d",f"-{cph}","-pass",f"pass:{passwd}","-md",md,"-in",MSG]
                        if "-nosalt" in extra and salted: continue
                        if "-nosalt" not in extra and not salted: cmd += ["-nosalt"]
                        try:
                            out = subprocess.run(cmd, capture_output=True, timeout=10).stdout
                        except Exception: continue
                        if not out: continue
                        printable = sum(1 for b in out if 9 <= b <= 126) / max(len(out),1)
                        if printable > 0.92 and len(out) > 20:
                            print(f"\n>>> POSSIVEL MENSAGEM  keyform={label}/{pflabel} cipher={cph} md={md} {extra}")
                            print(out[:800].decode("utf-8","replace"))
                            open(f"MENSAGEM_{label}_{cph}_{md}.txt","wb").write(out)

    # tambem: pbkdf2
    for label, key in keys_to_try:
        passforms = [("hex", key.hex())]
        try:
            txt = key.decode("ascii")
            if txt.isprintable(): passforms.append(("ascii", txt))
        except Exception: pass
        for pflabel, passwd in passforms:
            for cph in CIPHERS:
                cmd = ["openssl","enc","-d",f"-{cph}","-pbkdf2","-pass",f"pass:{passwd}","-in",MSG]
                try:
                    out = subprocess.run(cmd, capture_output=True, timeout=10).stdout
                except Exception: continue
                if not out: continue
                printable = sum(1 for b in out if 9 <= b <= 126) / max(len(out),1)
                if printable > 0.92 and len(out) > 20:
                    print(f"\n>>> POSSIVEL MENSAGEM (pbkdf2) keyform={label}/{pflabel} cipher={cph}")
                    print(out[:800].decode("utf-8","replace"))
                    open(f"MENSAGEM_pbkdf2_{label}_{cph}.txt","wb").write(out)

if __name__ == "__main__":
    main()
