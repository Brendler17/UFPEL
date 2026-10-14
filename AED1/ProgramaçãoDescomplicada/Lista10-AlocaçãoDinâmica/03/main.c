#include <stdio.h>
#include <stdlib.h>

int main() {
  int *array, *endArray;
  int size;
  int countEven = 0, countOdd = 0;

  printf("Digite o tamanho do vetor: ");
  scanf("%d", &size);

  array = malloc(size * sizeof(int));
  if (array == NULL) {
    printf("Erro ao alocar memória!");
    return 1;
  }

  endArray = array + size;

  printf("Digite %d números: ", size);
  for (int* loopArray = array; loopArray < endArray; loopArray++) {
    scanf("%d", loopArray);
  }

  printf("\nOs números pares são: ");
  for (int* loopArray = array; loopArray < endArray; loopArray++) {
    if (*loopArray % 2 == 0) {
      printf("%d ", *loopArray);
      countEven++;
    }
  }

  printf("\nOs números ímpares são: ");
  for (int* loopArray = array; loopArray < endArray; loopArray++) {
    if (*loopArray % 2 != 0) {
      printf("%d ", *loopArray);
      countOdd++;
    }
  }
  printf("\n\nQuantidade de números pares: %d", countEven);
  printf("\nQuantidade de números ímpares: %d", countOdd);
  printf("\n\n");

  free(array);

  return 0;
}