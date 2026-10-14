#include <stdio.h>

int main() {
  int array[5] = {1, 2, 3, 4, 5};
  int size = sizeof(array) / sizeof(array[0]);
  int* pointer = array;
  int* endArray = pointer + size;

  for (; pointer < endArray; pointer++) {
    *pointer += 1;
  }

  printf("O vetor após somar +1 a cada posição: \n");
  for (int counter = 0; counter < size; counter++) {
    printf("%d\t", array[counter]);
  }
  printf("\n");

  return 0;
}