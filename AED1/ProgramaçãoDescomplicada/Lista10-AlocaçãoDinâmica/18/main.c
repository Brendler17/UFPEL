#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char name[30];
  int code;
  float price;
} Product;

void freeMatrix(void **matrix, size_t numberOfLines) {
  if (matrix != NULL) {
    for (size_t line = 0; line < numberOfLines; line++) {
      free(matrix[line]);
    }

    free(matrix);
  }
}

int main() {
  void *array;
  size_t sizeArray = 1024;
  int **matrix = NULL;
  size_t numberOfLines = 10, numberOfColumns = 10;
  Product *productArray;
  size_t numberOfProducts = 50;
  char **text;
  size_t textLines = 100, textCharacters = 80;

  array = (void *)malloc(sizeArray);
  if (array == NULL) {
    printf("\nErro ao alocar memória!\n\n");
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
      freeMatrix((void **)matrix, line);
      return 1;
    }
  }

  productArray = (Product *)malloc(numberOfProducts * sizeof(Product));
  if (productArray == NULL) {
    printf("\nErro ao alocar memória!\n\n");
    return 1;
  }

  text = (char **)malloc(textLines * sizeof(char *));
  if (text == NULL) {
    printf("\nErro ao alocar memória!\n\n");
    return 1;
  }

  for (size_t line = 0; line < textLines; line++) {
    text[line] = (char *)malloc(textCharacters * sizeof(char));
    if (text[line] == NULL) {
      printf("\nErro ao alocar memória!\n\n");
      freeMatrix((void **)text, line);
      return 1;
    }
  }

  free(array);
  freeMatrix((void **)matrix, numberOfLines);
  free(productArray);
  freeMatrix((void **)text, textLines);

  return 0;
}