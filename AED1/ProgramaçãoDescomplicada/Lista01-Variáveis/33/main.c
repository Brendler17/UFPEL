#include <math.h>
#include <stdio.h>

int main() {
  float side;

  printf("Digite o tamanho do lado de um quadrado: ");
  scanf("%f", &side);
  printf("A área do quadrado é %.1f\n\n", pow(side, 2));

  return 0;
}