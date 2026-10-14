CC = gcc
CFLAGS = -O2 -Wall -Wextra
LIMITE_TEMPO = 600

all: aproximativo exato

aproximativo: src/aproximativo.c
	$(CC) $(CFLAGS) -o aproximativo src/aproximativo.c

exato: src/exato.c
	$(CC) $(CFLAGS) -o exato src/exato.c

# Roda o aproximativo em todas as instâncias da pasta data/
rodar-aproximativo: aproximativo
	@for f in data/*.txt; do ./aproximativo $$f; echo; done

# Roda o exato em todas as instâncias (limite: make rodar-exato LIMITE_TEMPO=60)
rodar-exato: exato
	@for f in data/*.txt; do ./exato $$f $(LIMITE_TEMPO); echo; done

limpar:
	rm -f aproximativo exato

.PHONY: all rodar-aproximativo rodar-exato limpar
