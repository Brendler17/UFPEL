#include <stdio.h>

int main() {
  float number;

  printf("Digite um número real: ");
  scanf("%f", &number);
  printf("O número digitado foi %.2f\n\n", number);

  return 0;
}