#include <stdio.h>
#include <stdlib.h>

void freeMatrix(int **matrix, size_t numberOfLines);

int getDimensions(size_t *lines, size_t *columns) {
  printf("Digite as dimensões da matriz (Linhas x Colunas): ");
  if (scanf("%zux%zu", lines, columns) != 2 || *lines <= 0 || *columns <= 0) {
    printf("\nValores inválidos!\n");
    return 1;
  }

  return 0;
}

int allocateMatrix(int ***matrix, size_t numberOfLines, size_t numberOfColumns) {
  *matrix = (int **)malloc(numberOfLines * sizeof(int *));
  if (*matrix == NULL) {
    printf("\nErro ao alocar memória!\n");
    return 1;
  }
  for (size_t line = 0; line < numberOfLines; line++) {
    (*matrix)[line] = (int *)malloc(numberOfColumns * sizeof(int));
    if ((*matrix)[line] == NULL) {
      freeMatrix(*matrix, line);
      printf("\nErro ao alocar memória!\n");
      return 1;
    }
  }

  return 0;
}

void fillMatrix(int **matrix, size_t numberOfLines, size_t numberOfColumns) {
  for (size_t line = 0; line < numberOfLines; line++) {
    for (size_t column = 0; column < numberOfColumns; column++) {
      printf("Digite o elemento para a posição [%zu][%zu]: ", line, column);
      scanf("%d", &matrix[line][column]);
    }
  }
}

void multiplyMatrix(int **matrixA, int **matrixB, int **resultMatrix, size_t numberOfLinesA, size_t numberOfColumnsA, size_t numberOfColumnsB) {
  for (size_t line = 0; line < numberOfLinesA; line++) {
    for (size_t column = 0; column < numberOfColumnsB; column++) {
      resultMatrix[line][column] = 0;
    }
  }

  for (size_t line = 0; line < numberOfLinesA; line++) {
    for (size_t column = 0; column < numberOfColumnsB; column++) {
      for (size_t k = 0; k < numberOfColumnsA; k++) {
        resultMatrix[line][column] += matrixA[line][k] * matrixB[k][column];
      }
    }
  }
}

void printMatrix(int **matrix, size_t numberOfLines, size_t numberOfColumns) {
  printf("\nO produto entre as duas matrizes é:\n");
  for (size_t line = 0; line < numberOfLines; line++) {
    for (size_t column = 0; column < numberOfColumns; column++) {
      printf("%d\t", matrix[line][column]);
    }
    printf("\n");
  }
  printf("\n\n");
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
  int **matrixA = NULL, **matrixB = NULL, **resultMatrix = NULL;
  size_t numberOfLinesA, numberOfColumnsA, numberOfLinesB, numberOfColumnsB, numberOfLinesResult, numberOfColumnsResult;

  if (getDimensions(&numberOfLinesA, &numberOfColumnsA)) {
    return 1;
  }

  if (getDimensions(&numberOfLinesB, &numberOfColumnsB)) {
    return 1;
  }

  if (numberOfColumnsA != numberOfLinesB) {
    printf("As matrizes não podem ser multiplicadas! O número de colunas da 1ª deve ser igual ao número de linhas da 2ª.\n");
    return 1;
  } else {
    numberOfLinesResult = numberOfLinesA;
    numberOfColumnsResult = numberOfColumnsB;
  }

  if (allocateMatrix(&matrixA, numberOfLinesA, numberOfColumnsA)) {
    return 1;
  }

  if (allocateMatrix(&matrixB, numberOfLinesB, numberOfColumnsB)) {
    freeMatrix(matrixA, numberOfLinesA);
    return 1;
  }

  if (allocateMatrix(&resultMatrix, numberOfLinesResult, numberOfColumnsResult)) {
    freeMatrix(matrixA, numberOfLinesA);
    freeMatrix(matrixB, numberOfLinesB);
    return 1;
  }

  printf("\nPreencha a primeira matriz:\n");
  fillMatrix(matrixA, numberOfLinesA, numberOfColumnsA);
  printf("\nPreencha a segunda matriz:\n");
  fillMatrix(matrixB, numberOfLinesB, numberOfColumnsB);
  multiplyMatrix(matrixA, matrixB, resultMatrix, numberOfLinesA, numberOfColumnsA, numberOfColumnsB);
  printMatrix(resultMatrix, numberOfLinesResult, numberOfColumnsResult);

  freeMatrix(matrixA, numberOfLinesA);
  freeMatrix(matrixB, numberOfLinesB);
  freeMatrix(resultMatrix, numberOfLinesResult);

  return 0;
}