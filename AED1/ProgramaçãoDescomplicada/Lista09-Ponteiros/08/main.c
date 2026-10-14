#include <stdio.h>

int main() {
  float array[10];

  for (int counter = 0; counter < 10; counter++) {
    printf("A posição %d do array está no endereço %p.\n", counter, (void *)&array[counter]);
  }
  printf("\n");

  return 0;
}