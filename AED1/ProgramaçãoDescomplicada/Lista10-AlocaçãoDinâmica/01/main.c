#include <stdio.h>
#include <stdlib.h>

int main() {
  int* array = malloc(sizeof(int) * 5);
  if (array == NULL) {
    printf("Erro ao alocar memória!");
    return 1;
  }

  int* startArray = array;
  int* endArray = array + 5;

  printf("Digite 5 números inteiros: ");
  for (; array < endArray; array++) {
    scanf("%d", array);
  }

  array = startArray;

  printf("Os 5 números do vetor são: ");
  for (; array < endArray; array++) {
    printf("%d\t", *array);
  }
  printf("\n\n");

  free(startArray);

  return 0;
}