#include <stdio.h>

void fillArray(void* array, int arraySize, int elementSize, int number) {
  int* lastPosition = array + arraySize * elementSize;

  for (int* currentPosition = array; currentPosition < lastPosition; currentPosition++) {
    *currentPosition = number;
  }
}

int main() {
  int array[10];
  int value = 7;
  int size = sizeof(array) / sizeof(array[0]);

  fillArray(&array[0], size, sizeof(int), value);

  for (int counter = 0; counter < size; counter++) {
    printf("%d\t", array[counter]);
  }

  printf("\n");

  return 0;
}