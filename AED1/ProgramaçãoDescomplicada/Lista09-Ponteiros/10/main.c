#include <stdio.h>

int main() {
  int array[5], *arrayPointer;

  arrayPointer = &array[0];

  for (int counter = 0; counter < 5; counter++) {
    printf("Digite o %dº valor: ", counter + 1);
    scanf("%d", arrayPointer);
    arrayPointer++;
  }

  arrayPointer = &array[0];

  for (int counter = 0; counter < 5; counter++) {
    *arrayPointer *= 2;
    printf("O dobro do %dº valor é: %d.\n", counter + 1, *arrayPointer);
    arrayPointer++;
  }

  return 0;
}