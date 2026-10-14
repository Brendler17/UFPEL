#include <stdio.h>

int main() {
  int array[5];

  for (int counter = 0; counter < 5; counter++) {
    printf("Digite o %dº valor: ", counter + 1);
    scanf("%d", &array[counter]);
  }

  for (int counter = 0; counter < 5; counter++) {
    if (array[counter] % 2 == 0) {
      printf("O endereço que o valor %d está é: %p.\n", array[counter], (void *)&array[counter]);
    }
  }

  return 0;
}