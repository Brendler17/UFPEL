#include <math.h>
#include <stdio.h>

int main() {
  float number;

  printf("Digite um número real: ");
  scanf("%f", &number);
  printf("A quinta parte do número digitado é %.2f\n\n", number / 5);

  return 0;
}