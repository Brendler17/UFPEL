#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void threeBiggest(int **matrix, size_t numberOfLines, size_t numberOfColumns) {
  int biggest[3] = {INT_MIN, INT_MIN, INT_MIN};

  for (int counter = 0; counter < 3; counter++) {
    int currentBiggest = INT_MIN;
    size_t currentLine = 0, currentColumn = 0;

    for (size_t line = 0; line < numberOfLines; line++) {
      for (size_t column = 0; column < numberOfColumns; column++) {
        int alreadyStored = 0;

        for (size_t arrayCounter = 0; arrayCounter < counter; arrayCounter++) {
          if (matrix[line][column] == biggest[arrayCounter]) {
            alreadyStored = 1;
            break;
          }
        }

        if (!alreadyStored && matrix[line][column] > currentBiggest) {
          currentBiggest = matrix[line][column];
          currentLine = line;
          currentColumn = column;
        }
      }
    }

    if (currentBiggest == INT_MIN) {
      printf("A matriz não possui elementos únicos suficientes.\n");
      break;
    }

    biggest[counter] = currentBiggest;

    printf("\nO %dº número mais alto da matriz é %d ", counter + 1, currentBiggest);
    printf("e está na posição [%zu][%zu].\n", currentLine, currentColumn);
  }
}

void freeMatrix(int **matrix, size_t numberOfLines) {
  if (matrix != NULL) {
    for (size_t line = 0; line < numberOfLines; line++) {
      free(matrix[line]);
    }

    free(matrix);
  }
}

int main() {
  int **matrix = NULL;
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
      printf("Digite o valor para a posição [%zu][%zu]: ", line, column);
      scanf("%d", &matrix[line][column]);
    }
  }

  threeBiggest(matrix, numberOfLines, numberOfColumns);

  freeMatrix(matrix, numberOfLines);

  return 0;
}