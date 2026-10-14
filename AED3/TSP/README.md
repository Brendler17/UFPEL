# Problema do Caixeiro Viajante (TSP)

Implementação em C de duas abordagens para o TSP:

- `src/exato.c`: algoritmo exato por Branch and Bound (backtracking com poda), com limite de tempo.
- `src/aproximativo.c`: algoritmo aproximativo da árvore (2-aproximativo), com MST pelo algoritmo de Prim O(n²) e percurso em pré-ordem.

## Requisitos

- Compilador C (GCC) e `make`.

Não há dependências externas.

## Compilação

Na pasta `TSP/`:

```bash
make
```

Isso gera os executáveis `aproximativo` e `exato`. Sem `make`:

```bash
gcc -O2 -o aproximativo src/aproximativo.c
gcc -O2 -o exato src/exato.c
```

## Execução

Uma instância:

```bash
./aproximativo data/tsp1_253.txt
./exato data/tsp1_253.txt         # limite padrão: 600 s
./exato data/tsp5_27603.txt 60    # limite de 60 s
```

Todas as instâncias:

```bash
make rodar-aproximativo
make rodar-exato                    # limite padrão: 600 s por instância
make rodar-exato LIMITE_TEMPO=60    # limite de 60 s por instância
```