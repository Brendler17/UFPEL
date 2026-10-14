#include <stdio.h>

int main() {
  float in, cm;

  printf("Digite o comprimento em polegadas: ");
  scanf("%f", &in);
  cm = in * 2.54;
  printf("O comprimento em centímetros é %.2f\n\n", cm);

  return 0;
}