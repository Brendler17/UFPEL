import hashlib
import itertools
import string

target = "1b78cdb61662342d53da0544a38c87579c4ca0e9b171ad2979f165a6b3e28cce"
prefix = "ma"

hashes = {
  "sha256": lambda s: hashlib.sha256(s).hexdigest(),
  "sha3_256": lambda s: hashlib.sha3_256(s).hexdigest(),
  "blake2s": lambda s: hashlib.blake2s(s).hexdigest(),
}

alphabet = string.ascii_lowercase

for n in range(0,6):
  print(f"Testando sufixos de tamanho {n}:")
  for combo in itertools.product(alphabet, repeat=n):
    candidate = prefix + "".join(combo)
    b = (candidate + "\n").encode()
    for name, fn in hashes.items():
      if fn(b) == target:
        print(f"Senha encontrada! >>> Senha='{candidate}' Algoritmo='{name}'")
        raise SystemExit

print("Nenhuma senha encontrada nessa busca!")