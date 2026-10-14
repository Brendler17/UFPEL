#include <math.h>
#include <stdio.h>

int main() {
  float number;

  printf("Digite um número real: ");
  scanf("%f", &number);
  printf("O quadrado do número digitado é %.2f\n\n", pow(number, 2));

  return 0;
}