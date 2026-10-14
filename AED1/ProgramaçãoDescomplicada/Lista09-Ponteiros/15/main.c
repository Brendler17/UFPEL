#include <stdio.h>

void printArray(void* array, int size, int sizeElement) {
  void* lastElement = array + size * sizeElement;

  for (void* currentElement = array; currentElement < lastElement; currentElement += sizeElement) {
    printf("%d\t", *(int*)currentElement);
  }

  printf("\n");
}

int main() {
  int array[5] = {1, 2, 3, 4, 5};
  int size = sizeof(array) / sizeof(array[0]);

  printArray(&array, size, sizeof(int));

  return 0;
}
