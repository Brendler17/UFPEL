#include <stdio.h>
#include <stdlib.h>

int isMultiple(int number, int numberArray) { return (numberArray % number == 0); }

int main() {
  int *array, *endArray;
  int size, number, numberOfMultiples = 0;

  printf("Digite o tamanho do array: ");
  scanf("%d", &size);

  array = (int*)malloc(size * sizeof(int));
  if (array == NULL) {
    printf("Erro ao alocar memória!");
    return 1;
  }

  endArray = array + size;

  printf("Digite %d números: ", size);
  for (int* loopArray = array; loopArray < endArray; loopArray++) {
    scanf("%d", loopArray);
  }

  printf("Digite um número: ");
  scanf("%d", &number);

  printf("Múltiplos de %d presentes no array: ", number);
  for (int* loopArray = array; loopArray < endArray; loopArray++) {
    if (isMultiple(number, *loopArray)) {
      printf("%d ", *loopArray);
      numberOfMultiples++;
    }
  }

  printf("\nO número %d tem %d múltiplo(s) presente(s) no array.\n\n", number, numberOfMultiples);

  free(array);

  return 0;
}