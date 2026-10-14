#include <stdio.h>

int main() {
  float cm, in;

  printf("Digite o comprimento em centímetros: ");
  scanf("%f", &cm);
  in = cm / 2.54;
  printf("O comprimento em polegadas é %.2f\n\n", in);

  return 0;
}