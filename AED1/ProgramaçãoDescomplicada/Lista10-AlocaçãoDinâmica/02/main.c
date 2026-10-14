#include <stdio.h>
#include <stdlib.h>

int main() {
  int *array, *startArray, *endArray;
  int size;

  printf("Digite o tamanho do vetor: ");
  scanf("%d", &size);

  array = malloc(size * sizeof(int));
  if (array == NULL) {
    printf("Erro ao alocar memória!");
    return 1;
  }

  startArray = array;
  endArray = array + size;

  printf("Digite %d números: ", size);
  for (; array < endArray; array++) {
    scanf("%d", array);
  }

  array = startArray;

  printf("\nOs %d números digitados foram:\n", size);
  for (; array < endArray; array++) {
    printf("%d\t", *array);
  }
  printf("\n\n");

  free(startArray);

  return 0;
}