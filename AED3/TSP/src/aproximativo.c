#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_VERTICES 100

int num_vertices;
int matriz[MAX_VERTICES][MAX_VERTICES];

int pai[MAX_VERTICES];
int rota[MAX_VERTICES + 1];
int tamanho_rota = 0;

int ler_matriz(const char* caminho) {
  FILE* arquivo = fopen(caminho, "r");
  if (!arquivo) {
    fprintf(stderr, "Erro: nao foi possivel abrir '%s'\n", caminho);
    return 0;
  }

  char linha[8192];
  if (!fgets(linha, sizeof(linha), arquivo)) {
    fclose(arquivo);
    return 0;
  }

  num_vertices = 0;
  char* numero = strtok(linha, " \t\r\n");
  while (numero) {
    num_vertices++;
    numero = strtok(NULL, " \t\r\n");
  }
  if (num_vertices < 2 || num_vertices > MAX_VERTICES) {
    fprintf(stderr, "Erro: tamanho de matriz invalido (%d)\n", num_vertices);
    fclose(arquivo);
    return 0;
  }

  rewind(arquivo);
  for (int i = 0; i < num_vertices; i++)
    for (int j = 0; j < num_vertices; j++)
      if (fscanf(arquivo, "%d", &matriz[i][j]) != 1) {
        fprintf(stderr, "Erro: matriz incompleta no arquivo\n");
        fclose(arquivo);
        return 0;
      }

  fclose(arquivo);
  return 1;
}

void prim(void) {
  int chave[MAX_VERTICES];
  int na_arvore[MAX_VERTICES];

  for (int v = 0; v < num_vertices; v++) {
    chave[v] = INT_MAX;
    na_arvore[v] = 0;
    pai[v] = -1;
  }
  chave[0] = 0;

  for (int iteracao = 0; iteracao < num_vertices; iteracao++) {
    int u = -1;
    for (int v = 0; v < num_vertices; v++)
      if (!na_arvore[v] && (u == -1 || chave[v] < chave[u])) u = v;

    na_arvore[u] = 1;

    for (int v = 0; v < num_vertices; v++)
      if (!na_arvore[v] && matriz[u][v] < chave[v]) {
        chave[v] = matriz[u][v];
        pai[v] = u;
      }
  }
}

void pre_ordem(int u) {
  rota[tamanho_rota++] = u;
  for (int v = 0; v < num_vertices; v++)
    if (pai[v] == u) pre_ordem(v);
}

int custo_rota(void) {
  int custo = 0;
  for (int i = 0; i < tamanho_rota - 1; i++) custo += matriz[rota[i]][rota[i + 1]];
  return custo;
}

int otimo_do_nome_arquivo(const char* caminho) {
  const char* sublinhado = strrchr(caminho, '_');
  return sublinhado ? atoi(sublinhado + 1) : 0;
}

double tempo_atual_segundos(void) {
  struct timespec t;
  clock_gettime(CLOCK_MONOTONIC, &t);
  return t.tv_sec + t.tv_nsec / 1e9;
}

int main(int argc, char* argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Uso: %s <arquivo_da_instancia>\n", argv[0]);
    return 1;
  }
  if (!ler_matriz(argv[1])) return 1;

  double inicio = tempo_atual_segundos();

  prim();
  tamanho_rota = 0;
  pre_ordem(0);
  rota[tamanho_rota++] = 0;

  double tempo_decorrido = tempo_atual_segundos() - inicio;

  /* ----------------------- Resultados ----------------------- */
  int custo = custo_rota();
  int otimo = otimo_do_nome_arquivo(argv[1]);

  printf("Arquivo: %s\n", argv[1]);
  printf("Vertices: %d\n", num_vertices);
  printf("Rota: ");
  for (int i = 0; i < tamanho_rota; i++) printf("%d%s", rota[i], i < tamanho_rota - 1 ? " -> " : "\n");
  printf("Custo: %d\n", custo);
  if (otimo > 0) {
    printf("Otimo: %d\n", otimo);
    printf("Razao (custo/otimo): %.3f\n", (double)custo / otimo);
    printf("Gap: %.2f%%\n", 100.0 * (custo - otimo) / otimo);
  }
  printf("Tempo: %.2f us\n", tempo_decorrido * 1e6);

  return 0;
}