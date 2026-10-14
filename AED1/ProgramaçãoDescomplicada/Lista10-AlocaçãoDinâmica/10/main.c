#include <stdio.h>
#include <stdlib.h>

int main() {
  double* array;
  size_t size;

  do {
    printf("Digite o número de elementos que deseja armazenar (min 10): ");
    scanf("%zu", &size);

    if (size < 10) {
      printf("\nO tamanho deve ser maior ou igual a 10.\n\n");
    }
  } while (size < 10);

  array = (double*)malloc(size * sizeof(double));
  if (array == NULL) {
    printf("\nErro ao alocar memória!\n\n");
    return 1;
  }

  for (int counter = 0; counter < size; counter++) {
    array[counter] = (rand() % 100) + 1;
  }

  printf("Os valores nas 10 primeiras posições do vetor são: ");
  for (int counter = 0; counter < 10; counter++) {
    printf("%.f ", array[counter]);
  }

  printf("\n\n");

  free(array);

  return 0;
}