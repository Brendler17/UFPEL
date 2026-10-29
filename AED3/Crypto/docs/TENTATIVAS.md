# Registro de tentativas — Criptoanálise (Grupo 2)

Alvo do hash: `1b78cdb61662342d53da0544a38c87579c4ca0e9b171ad2979f165a6b3e28cce`
(64 hex = **256 bits**). Pista: a senha começa com `ma`.

- Terminadores testados em todos os casos: `""` (sem nada) e `"\n"`.
- Hashes de 256 bits usados como rede de segurança: `sha256`, `sha3_256`,
  `sha512_256`, `blake2s`, `sm3`, `keccak256`, `shake_256`. Assumimos **SHA-256
  padrão** (não há função de hash customizada no material do desafio) — confirmado
  ao final.

## Arquitetura do desafio (descoberta por inspeção dos arquivos)
- `message.en` (1482 B): `file` → *"openssl enc'd data with salted password"*
  (header `Salted__` + 8 B de salt). Ciphertext = 1466 B, **não múltiplo de 16**
  → cifra de **fluxo** (AES-CTR/CFB/OFB).
- `key_for_message.en` (48 B = **384 bits**): tamanho de ciphertext **RSA-384**
  → módulo pequeno, **fatorável**.
- `key_public.en` (157 B): cifrado simetricamente; decifra (com a senha) → chave pública RSA.
- Cadeia: quebrar senha → decifrar `key_public.en` → fatorar `N` → reconstruir chave
  privada → decifrar `key_for_message.en` → chave simétrica → `openssl enc -d` em
  `message.en` → mensagem.

## Etapa 1 — quebra do hash da senha (SHA-256)

| #  | Abordagem | Espaço | Algoritmos | Resultado |
|----|-----------|--------|------------|-----------|
| 1  | Brute `ma`+`[a-z]` ≤5 | ~12M | sha256/sha3_256/blake2s | ✗ |
| 2  | Dicionário temático + mangling | ~2k | 15 | ✗ |
| 3  | rockyou prefixo `ma` (utf-8) | 330k | 15 | ✗ |
| 4  | rockyou prefixo `ma` (bytes crus, corrige encoding) | 330k | 12 | ✗ |
| 5  | Dicionário PT/EN/cracklib `ma*` + mangling (3 encodings) | 10k bases | 13 | ✗ |
| 6  | Temático + nomes do grupo + compostos (ano/leet) | ~10k | 15 | ✗ |
| 7  | Brute `ma`+`[a-z0-9]` ≤6 (até 8 chars) | 2,1B | sha256 | ✗ |
| 8  | Brute `ma`+`[a-zA-Z0-9!@#$%_-.]` ≤5 (até 7 chars) | 1,7B | sha256 | ✗ |
| 9  | rockyou `ma*` + regras best64 (sufixos/anos/leet/dup) | 69M | sha256 | ✗ |
| 10 | rockyou `ma*` + regras best64 | 69M | sha3_256 | ✗ |
| 11 | rockyou `ma*` + regras best64 | 69M | blake2s | ✗ |
| 12 | rockyou `ma*` + regras best64 | 69M | keccak256, sha512_256 | ✗ |
| 13 | rockyou `ma*` + dict `ma*` | — | sm3, shake_256 | ✗ |
| 14 | Brute `ma`+`[a-z0-9]` ≤6 (multi-hash C) | 2,1B×3 | sha3_256, blake2s, keccak256 | ✗ |
| 15 | Construções alternativas (double-hash, hex/b64/rev input, md5→sha) | 900k ×12 | — | ✗ |
| 16 | Brute prefixo `Ma` e `MA` +`[a-z0-9]` ≤5 | 60M×8 | sha256, sha3_256, blake2s, keccak256 | ✗ |
| 17 | Brute `ma`+`[a-z0-9]` ≤6 | 2,1B×3 | sha512_256, sm3, shake256 | ✗ |
| 18 | Frases/compostos temáticos (PL/DE/PT/EN, separadores, anos) | 194k | 7 | ✗ |
| 19 | Brute `ma`+`[a-zA-Z0-9]` ≤5 (caixa mista) | 916M | sha256, sha3_256 | ✗ |
| 20 | Encodings utf-16le/be/bom/utf-32 (rockyou + brute curto) | — | 7 | ✗ |
| 21 | Lote ordenado: `[a-z]` len7/len8, mix len5/6, `[a-z0-9]` len7 | bilhões | 7 | ✗ |
| 22 | Brute `[a-zA-Z0-9]` len6 (8 chars, caixa mista) | 916M | sha256 | ✗ |
| 23 | Frases temáticas longas (concatenações Enigma/cripto) | — | 7 | ✗ |
| 24 | Concatenações temáticas 1-3 palavras (Enigma/cripto/PL/PT) | 31M | sha256 | ✗ |
| 25 | Frases famosas/músicas (EN+BR) começando `ma` + variações | — | 7 | ✗ |
| 26 | Combinador palavra-`ma` (dict) × termos temáticos (×135) | 1,17M | 4 | ✗ |
| 27 | Nomes do grupo concatenados | 10,9k | 7 | ✗ |
| 28 | Rede de segurança: brute `[a-z0-9]` len7 (9ch), `[a-z]` len8 (10ch) | bilhões | sha256 | ✗ |
| 29 | Combinador amplo: palavra-`ma` (dict) × palavra comum (dict/cracklib) | — | sha256 | ✗ |
| 30 | Contexto ampliado (PL/DE/EN/PT, 2-3 palavras) | — | sha256 | ✗ |
| 31 | Nomes dos 3 criptoanalistas do Biuro + termos Enigma | 150k | 7 | ✗ |
| 32 | Primeiras-linhas de músicas famosas (EN+BR) | — | 7 | ✗ |
| 33 | **Combinador de 2 palavras** (palavra-`ma` × dicionário completo, C+OpenMP) | — | sha256 | ✅ **`marvinminsky`** |

### Ataque paralelo ao RSA (contornar a senha) — falhou
Tentativa de recuperar a chave simétrica direto de `key_for_message.en` (48 B) com
RSA "textbook" e expoente pequeno (`m = raiz e-ésima de c`, `e ∈ {3,5,7,11,17,257,65537}`,
big/little-endian): **sem raiz exata**. `c` tem 381 bits < N(384) → há redução modular
→ é preciso de `N` (ou seja, da senha). Sem atalho.

### Por que a maior parte falhou
A força bruta até ~10 caracteres e os dicionários/*rockyou* (com regras best64, leet,
anos e 3 encodings) não alcançam a senha porque ela é a **concatenação de dois nomes**
(`marvin` + `minsky`), não uma palavra isolada nem variação trivial. Só um **combinador
de duas palavras** sobre um dicionário amplo a encontraria (tentativa 33). A hipótese
inicial de *passphrase* longa (15+ caracteres) mostrou-se falsa.

## Solução completa — cadeia inteira decifrada

1. **Senha (SHA-256):** `marvinminsky` — "marvin" + "minsky" (**Marvin Minsky**),
   começa com `ma`, minúscula, 12 chars, sem terminador.
   `echo -n marvinminsky | sha256sum` = `1b78…28cce` ✓
2. **key_public.en → chave pública RSA:**
   `openssl enc -d -aes-256-ctr -nosalt -md sha256 -pass pass:marvinminsky -in key_public.en`
   → PEM RSA, **N de 382 bits**, `e = 65537`.
3. **Fatoração de N (GNFS / CADO-NFS):** ~2h38 de CPU (`-t 4`), tempo real ~2h39.
   - `p = 1967103988726232522467829353610346625438028501545676588173`
   - `q = 2953425116275607543642880749640518195177306268255592720967`
   - `p·q = N` ✓ (ambos primos). Python puro (Fermat/Pollard/Brent) não resolve
     primos balanceados → GNFS necessário.
4. **key_for_message.en (RSA-384) → chave simétrica:**
   `d = e⁻¹ mod φ(N)`; `m = c^d mod N`; **padding PKCS#1 v1.5** → payload `shafigoldwas`.
5. **message.en → mensagem final:**
   `openssl enc -d -aes-256-cfb -md sha256 -pass pass:shafigoldwas -in message.en`
   → texto claro (1466 B), endereçado ao Grupo 2. Salvo em
   `results/MENSAGEM_pkcs1_aes-256-cfb_sha256.txt`.

### Toolchain de fatoração (compilado sem privilégios de administrador)
- Compilado do zero: **m4** → **GMP 6.3.0** → **CADO-NFS** (GNFS).
- `cmake` via `pip` (ambiente virtual); dependências Python do CADO (`flask`,
  `requests`) em diretório próprio via `--target` + `PYTHONPATH`.
- Build do CADO com `-j2`/`nice` (o `-j8` estourava a memória).

### Observações
- Senha e chave simétrica são ambas **nomes de pioneiros da computação/IA**
  (`marvinminsky`; `shafigoldwas` = "Shafi Goldwasser" truncado em 12 B pelo RSA-384).
- RSA de **baixa entropia** (N de 382 bits, fatorável por GNFS) — a própria mensagem
  final explica essa vulnerabilidade.
