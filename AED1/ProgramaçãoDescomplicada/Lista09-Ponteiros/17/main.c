#include <stdio.h>

void frac(float num, int* inteiro, float* frac) {
  *inteiro = (int)num;
  *frac = num - *inteiro;
}

int main() {
  float number, fractional;
  int integer;

  printf("Digite um número real: ");
  scanf("%f", &number);

  frac(number, &integer, &fractional);

  printf("Parte inteira: %d\n", integer);
  printf("Parte fracionária: %.2f\n", fractional);

  return 0;
}
