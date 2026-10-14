#include <stdio.h>
#include <stdlib.h>

int main() {
  size_t lenght = 1500, range = 10;
  int countZero = 0;
  int *array, *endArray, *startRange, *endRange;

  array = (int *)calloc(lenght, sizeof(int));
  if (array == NULL) {
    printf("Erro ao alocar memória!");
    return 1;
  }

  for (int counter = 0; counter < lenght; counter++) {
    if (array[counter] == 0) {
      countZero++;
    }

    array[counter] = counter;
  }

  printf("Contagem de zeros: %d\n\n", countZero);

  endArray = array + lenght;
  startRange = array + range;
  endRange = endArray - range;

  printf("Os %d primeiros números do vetor são:\n", (int)range);
  for (int *loopArray = array; loopArray < startRange; loopArray++) {
    printf("%d ", *loopArray);
  }

  printf("\n\nOs %d últimos números do vetor são:\n", (int)range);
  for (int *loopArray = endRange; loopArray < endArray; loopArray++) {
    printf("%d ", *loopArray);
  }

  printf("\n\n");

  free(array);

  return 0;
}