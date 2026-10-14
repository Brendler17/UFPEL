#include <stdio.h>

int main() {
  float l, m3;

  printf("Digite o volume em litros: ");
  scanf("%f", &l);
  m3 = l / 1000;
  printf("O volume em metros cúbicos é %.4f\n\n", m3);

  return 0;
}