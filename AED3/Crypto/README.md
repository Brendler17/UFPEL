# Criptoanálise de um Esquema Híbrido RSA + AES

**AED3 — Algoritmos e Estruturas de Dados III · UFPel · Prof. Ulisses Brisolara Correa**
**Grupo 2 — Gabriel Madureira e Gustavo Brendler**

Criptoanálise completa de um desafio no tema do *Biuro Szyfrów* (a seção polonesa
que quebrou a Enigma). A partir de quatro artefatos — um *hash* e três arquivos
cifrados — recuperamos a mensagem em claro quebrando toda a cadeia híbrida RSA + AES.

## Estrutura do repositório

```
Crypto/
├─ README.md                 # este arquivo
├─ description/              # material de entrada do desafio (enunciado + artefatos)
│  ├─ enunciado.txt          #   enunciado do trabalho
│  ├─ key_for_rsa_public.hash#   hash (SHA-256) da senha da chave pública
│  ├─ key_public.en          #   chave pública RSA, cifrada simetricamente
│  ├─ key_for_message.en     #   chave da mensagem, protegida por RSA
│  └─ message.en             #   mensagem secreta cifrada
├─ src/                      # código da solução (apenas o que funcionou)
│  ├─ brute_combine.c        #   quebra da senha — combinador de 2 palavras (SHA-256, C+OpenMP)
│  ├─ decrypt_pubkey.py      #   decifra key_public.en → chave pública RSA
│  ├─ factor_rsa.py          #   fatoração elementar (Fermat/Pollard/Brent — pré-GNFS)
│  └─ finish.py              #   reconstrói a chave privada e decifra a mensagem
├─ docs/
│  ├─ relatorio.tex          # relatório (fonte LaTeX)
│  ├─ relatorio.pdf          # relatório (PDF)
│  └─ TENTATIVAS.md          # log bruto das ~36 tentativas (inclui as que falharam)
└─ results/
   ├─ SENHA_ACHADA.flag      # senha recuperada (marvinminsky, sha256)
   └─ MENSAGEM_pkcs1_aes-256-cfb_sha256.txt  # mensagem final decifrada
```

> Os quatro artefatos **de entrada** do desafio (`key_for_rsa_public.hash`,
> `key_public.en`, `key_for_message.en`, `message.en`) e o enunciado estão em
> `description/`. Os scripts em `src/` leem esses arquivos por caminho relativo
> (`../description/`), então o repositório é replicável do zero sem ajustes.

## Cadeia da solução

```
senha ──SHA-256──▶ hash (alvo)
  │ (quebrar o hash: combinador de 2 palavras)
  ▼
senha ──AES──▶ decifra key_public.en ⇒ chave pública RSA (N, e)
  │ (fatorar N, 382 bits, via GNFS/CADO-NFS)
  ▼
N = p·q ⇒ d = e⁻¹ mod φ(N)   (chave privada)
  │
  ▼
key_for_message.en ──RSA: c^d mod N──▶ chave simétrica da mensagem
  │
  ▼
message.en ──AES──▶ MENSAGEM EM CLARO
```

| Etapa | Resultado |
|---|---|
| Senha (SHA-256) | `marvinminsky` (Marvin Minsky) |
| Módulo RSA | `N` de 382 bits, fatorado por GNFS (CADO-NFS, ~2h39) |
| Chave simétrica | `shafigoldwas` (Shafi Goldwasser, truncada pelo RSA-384) |
| Mensagem | endereçada ao Grupo 2 — ver `results/MENSAGEM_...txt` |

## Reprodução

```bash
# 1. Senha — compilar e rodar o combinador
gcc -O3 -fopenmp -o brute_combine src/brute_combine.c
./brute_combine mawords.txt allwords.txt 10        # ⇒ marvinminsky
#   (mawords.txt = palavras iniciadas em "ma"; allwords.txt = dicionário amplo)

# 2. Chave pública RSA
openssl enc -d -aes-256-ctr -nosalt -md sha256 \
    -pass pass:marvinminsky -in key_public.en
openssl rsa -pubin -in pub.pem -text -noout        # extrai N, e

# 3. Fatorar N (GNFS)
./cado-nfs.py <N> -t 4                              # ⇒ p, q

# 4. Chave simétrica + mensagem final
python3 src/finish.py <p> <q>
```

## Abordagens que falharam

As tentativas sem sucesso (força bruta curta, dicionário/*rockyou* + regras,
*passphrases* temáticas, "textbook RSA", fatoração elementar) estão resumidas por
família na seção *"Abordagens que falharam (e por quê)"* do relatório
(`docs/relatorio.pdf`) e registradas em detalhe em `docs/TENTATIVAS.md`.

## Compilar o relatório

```bash
cd docs
pdflatex relatorio.tex && pdflatex relatorio.tex   # 2x (sumário + referências)
```
Os caminhos de `\lstinputlisting` são relativos a `docs/` (`../src/`, `../results/`),
então compile a partir de dentro de `docs/`.
