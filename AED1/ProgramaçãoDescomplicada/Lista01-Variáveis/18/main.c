#include <stdio.h>

int main() {
  float m3, l;

  printf("Digite o volume em metros cúbicos: ");
  scanf("%f", &m3);
  l = 1000 * m3;
  printf("O volume em litros é %.1f\n\n", l);

  return 0;
}