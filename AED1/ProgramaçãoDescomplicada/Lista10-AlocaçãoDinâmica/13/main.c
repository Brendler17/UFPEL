#include <stdio.h>
#include <stdlib.h>

int isPresentInTheMatrix(int** matrix, size_t numberOfLines, size_t numberOfColumns) {
  int targetNumber;

  printf("\nDigite um número para verificar se está presente na matriz: ");
  scanf("%d", &targetNumber);

  for (size_t line = 0; line < numberOfLines; line++) {
    for (size_t column = 0; column < numberOfColumns; column++) {
      if (matrix[line][column] == targetNumber) {
        return 1;
      }
    }
  }

  return 0;
}

void freeMatrix(int** matrix, size_t numberOfLines) {
  if (matrix != NULL) {
    for (size_t line = 0; line < numberOfLines; line++) {
      free(matrix[line]);
    }

    free(matrix);
  }
}

int main() {
  int** matrix = NULL;
  int presentInTheMatrix;
  size_t numberOfLines, numberOfColumns;

  printf("Digite as dimensões de uma matriz (Linhas x Colunas): ");
  scanf("%zux%zu", &numberOfLines, &numberOfColumns);

  matrix = (int**)malloc(numberOfLines * sizeof(int*));
  if (matrix == NULL) {
    printf("Erro ao alocar memória!\n");
    return 1;
  }

  for (size_t line = 0; line < numberOfLines; line++) {
    matrix[line] = (int*)malloc(numberOfColumns * sizeof(int));
    if (matrix[line] == NULL) {
      printf("Erro ao alocar memória!\n");
      freeMatrix(matrix, line);
      return 1;
    }
  }

  for (size_t line = 0; line < numberOfLines; line++) {
    for (size_t column = 0; column < numberOfColumns; column++) {
      printf("Preencha o valor para a posição [%zu][%zu]: ", line, column);
      scanf("%d", &matrix[line][column]);
    }
  }

  presentInTheMatrix = isPresentInTheMatrix(matrix, numberOfLines, numberOfColumns);

  presentInTheMatrix ? printf("\nPresente na matriz!\n\n") : printf("\nNão está presente na matriz!\n\n");

  freeMatrix(matrix, numberOfLines);

  return 0;
}