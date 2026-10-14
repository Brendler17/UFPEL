#include <stdio.h>

int main() {
  float m, yd;

  printf("Digite o comprimento em metros: ");
  scanf("%f", &m);
  yd = m / 0.91;
  printf("O comprimento em jardas é %.1f\n\n", yd);

  return 0;
}
