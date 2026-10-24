import hashlib

target = "1b78cdb61662342d53da0544a38c87579c4ca0e9b171ad2979f165a6b3e28cce"

hashes = {
  "sha256": lambda s: hashlib.sha256(s).hexdigest(),
  "sha3_256": lambda s: hashlib.sha3_256(s).hexdigest(),
  "blake2s": lambda s: hashlib.blake2s(s).hexdigest(),
}

with open("words.txt", encoding="utf-8") as file:
  lines = [line.strip() for line in file if line.strip()]

bases = set()
for line in lines:
  parts = line.split()
  part = set(parts)
  part.add(line)
  part.add("".join(parts))
  part.add("_".join(parts))
  part.add(".".join(parts))
  part.add("-".join(parts))

  if len(parts) == 2:
    part.add(parts[1] + parts[0])
    part.add(f"{parts[0]} {parts[1]}")
  bases |= part

def caps(p):
  return {p, p.lower(), p.upper(), p.capitalize(), p.title()}

candidates = set()
for b in bases:
  for c in caps(b):
    candidates.add(c)
    for year in range(1900, 2027):
      candidates.add(f"{c}{year}")

found = False
for cand in candidates:
  for end in ("", "\n"):
    data = (cand + end).encode()
    for name, fn in hashes.items():
      if fn(data) == target:
        print(f">>> Senha encontrada! Senha={cand!r} "
              f"Newline={end == chr(10)} Algoritmo={name}")
        found = True
        raise SystemExit

if not found:
  print(f"Nenhuma senha encontrada na busca das bases ({len(candidates)})")