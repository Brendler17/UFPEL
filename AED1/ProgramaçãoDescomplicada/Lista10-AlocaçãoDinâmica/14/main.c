#include <stdio.h>
#include <stdlib.h>

void freeMatrix(float **matrix, size_t numberOfLines) {
  if (matrix != NULL) {
    for (size_t line = 0; line < numberOfLines; line++) {
      free(matrix[line]);
    }

    free(matrix);
  }
}

int main() {
  float **matrix = NULL;
  size_t numberOfLines, numberOfColumns;

  printf("Digite as dimensões da matrix (Linhas x Colunas): ");
  if (scanf("%zux%zu", &numberOfLines, &numberOfColumns) != 2 || numberOfLines <= 0 || numberOfColumns <= 0) {
    printf("\nErro! Dimensões inválidas.\n\n");
    return 1;
  }

  matrix = (float **)malloc(numberOfLines * sizeof(float *));
  if (matrix == NULL) {
    printf("\nErro ao alocar memória!\n\n");
    return 1;
  }

  for (size_t line = 0; line < numberOfLines; line++) {
    matrix[line] = (float *)malloc(numberOfColumns * sizeof(float));
    if (matrix[line] == NULL) {
      printf("\nErro ao alocar memória!\n\n");
      freeMatrix(matrix, line);
      return 1;
    }
  }

  for (size_t line = 0; line < numberOfLines; line++) {
    for (size_t column = 0; column < numberOfColumns; column++) {
      printf("Digite o valor para a posição [%zu][%zu]: ", line, column);
      scanf("%f", &matrix[line][column]);
    }
  }

  printf("\nO resultado da matriz é:\n");
  for (size_t line = 0; line < numberOfLines; line++) {
    for (size_t column = 0; column < numberOfColumns; column++) {
      printf("%.1f\t", matrix[line][column]);
    }
    printf("\n");
  }

  printf("\n\n");

  freeMatrix(matrix, numberOfLines);

  return 0;
}