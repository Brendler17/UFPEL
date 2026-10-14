#include <stdio.h>

int main() {
  float yd, m;

  printf("Digite o comprimento em jardas: ");
  scanf("%f", &yd);
  m = yd * 0.91;
  printf("O comprimento em metros é %.3f\n\n", m);

  return 0;
}
