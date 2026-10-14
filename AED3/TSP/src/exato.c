#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_VERTICES 100
#define LIMITE_TEMPO_PADRAO 600.0
#define INTERVALO_VERIFICACAO 1000000

int num_vertices;
int matriz[MAX_VERTICES][MAX_VERTICES];

int visitado[MAX_VERTICES];
int rota[MAX_VERTICES];
int melhor_rota[MAX_VERTICES];
int melhor_custo = INT_MAX;

double tempo_inicio;
double limite_tempo = LIMITE_TEMPO_PADRAO;
int tempo_esgotado = 0;
long long chamadas = 0;

double tempo_atual_segundos(void) {
  struct timespec t;
  clock_gettime(CLOCK_MONOTONIC, &t);
  return t.tv_sec + t.tv_nsec / 1e9;
}

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

void branch_and_bound(int nivel, int atual, int custo_parcial) {
  if (tempo_esgotado) return;

  if (++chamadas % INTERVALO_VERIFICACAO == 0 && tempo_atual_segundos() - tempo_inicio > limite_tempo) {
    tempo_esgotado = 1;
    return;
  }

  if (custo_parcial >= melhor_custo) return;

  if (nivel == num_vertices) {
    int custo_total = custo_parcial + matriz[atual][0];
    if (custo_total < melhor_custo) {
      melhor_custo = custo_total;
      memcpy(melhor_rota, rota, num_vertices * sizeof(int));
    }
    return;
  }

  for (int v = 1; v < num_vertices; v++) {
    if (!visitado[v]) {
      visitado[v] = 1;
      rota[nivel] = v;
      branch_and_bound(nivel + 1, v, custo_parcial + matriz[atual][v]);
      visitado[v] = 0;
    }
  }
}

int otimo_do_nome_arquivo(const char* caminho) {
  const char* sublinhado = strrchr(caminho, '_');
  return sublinhado ? atoi(sublinhado + 1) : 0;
}

int main(int argc, char* argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Uso: %s <arquivo_da_instancia> [limite_em_segundos]\n", argv[0]);
    return 1;
  }
  if (argc >= 3) limite_tempo = atof(argv[2]);
  if (!ler_matriz(argv[1])) return 1;

  memset(visitado, 0, sizeof(visitado));
  visitado[0] = 1;
  rota[0] = 0;

  tempo_inicio = tempo_atual_segundos();
  branch_and_bound(1, 0, 0);
  double tempo_decorrido = tempo_atual_segundos() - tempo_inicio;

  /* ----------------------- Resultados ----------------------- */
  int otimo = otimo_do_nome_arquivo(argv[1]);

  printf("Arquivo: %s\n", argv[1]);
  printf("Vertices: %d\n", num_vertices);

  if (tempo_esgotado) printf("TEMPO ESGOTADO (limite de %.0f s): resultado abaixo NAO e garantidamente otimo\n", limite_tempo);

  if (melhor_custo == INT_MAX) {
    printf("Nenhuma rota completa encontrada.\n");
  } else {
    printf("Rota: ");
    for (int i = 0; i < num_vertices; i++) printf("%d -> ", melhor_rota[i]);
    printf("0\n");
    printf("Custo: %d\n", melhor_custo);
    if (otimo > 0) {
      printf("Otimo: %d\n", otimo);
      printf("Gap: %.2f%%\n", 100.0 * (melhor_custo - otimo) / otimo);
    }
  }
  printf("Nos explorados: %lld\n", chamadas);
  printf("Tempo: %.6f s\n", tempo_decorrido);

  return 0;
}