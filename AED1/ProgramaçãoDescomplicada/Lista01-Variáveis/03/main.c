#include <stdio.h>

int main() {
  int numbers[3], sum;

  for (int counter = 0; counter < 3; counter++) {
    printf("Digite um número: ");
    scanf("%d", &numbers[counter]);
    sum += numbers[counter];
  }

  printf("A soma dos números digitados é %d.\n\n", sum);

  return 0;
}