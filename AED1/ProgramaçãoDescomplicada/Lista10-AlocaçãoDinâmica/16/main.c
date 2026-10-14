#include <stdio.h>
#include <stdlib.h>

void freeMatrix(int **matrix, size_t numberOfLines) {
  if (matrix != NULL) {
    for (size_t line = 0; line < numberOfLines; line++) {
      free(matrix[line]);
    }

    free(matrix);
  }
}

int main() {
  int **matrix = NULL, **transposedMatrix = NULL;
  size_t numberOfLines, numberOfColumns;

  printf("Digite as dimensões da matriz (Linhas x Colunas): ");
  if (scanf("%zux%zu", &numberOfLines, &numberOfColumns) != 2 || numberOfLines <= 0 || numberOfColumns <= 0) {
    printf("\nErro! Dimensões inválidas.\n\n");
    return 1;
  }

  matrix = (int **)malloc(numberOfLines * sizeof(int *));
  if (matrix == NULL) {
    printf("\nErro ao alocar memória!\n\n");
    return 1;
  }

  for (size_t line = 0; line < numberOfLines; line++) {
    matrix[line] = (int *)malloc(numberOfColumns * sizeof(int));
    if (matrix[line] == NULL) {
      printf("\nErro ao alocar memória!\n\n");
      freeMatrix(matrix, line);
      return 1;
    }
  }

  for (size_t line = 0; line < numberOfLines; line++) {
    for (size_t column = 0; column < numberOfColumns; column++) {
      printf("Digite o valor da posição [%zu][%zu]: ", line, column);
      scanf("%d", &matrix[line][column]);
    }
  }

  printf("\nA matriz original é:\n");
  for (size_t line = 0; line < numberOfLines; line++) {
    for (size_t column = 0; column < numberOfColumns; column++) {
      printf("%d\t", matrix[line][column]);
    }
    printf("\n");
  }

  size_t transposedLines = numberOfColumns;
  size_t transposedColumns = numberOfLines;

  transposedMatrix = (int **)malloc(transposedLines * sizeof(int *));
  if (transposedMatrix == NULL) {
    printf("\nErro ao alocar memória!\n\n");
    return 1;
  }

  for (size_t line = 0; line < transposedLines; line++) {
    transposedMatrix[line] = (int *)malloc(transposedColumns * sizeof(int));
    if (transposedMatrix[line] == NULL) {
      printf("\nErro ao alocar memória!\n\n");
      freeMatrix(transposedMatrix, line);
      return 1;
    }
  }

  for (size_t line = 0; line < transposedLines; line++) {
    for (size_t column = 0; column < transposedColumns; column++) {
      transposedMatrix[line][column] = matrix[column][line];
    }
  }

  printf("\nA matriz transposta é:\n");
  for (size_t line = 0; line < transposedLines; line++) {
    for (size_t column = 0; column < transposedColumns; column++) {
      printf("%d\t", transposedMatrix[line][column]);
    }
    printf("\n");
  }

  printf("\n\n");

  freeMatrix(matrix, numberOfLines);
  freeMatrix(transposedMatrix, transposedLines);

  return 0;
}