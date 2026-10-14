#include <stdio.h>

static float pi = 3.14;

int main() {
  float angle, rad;

  printf("Digite o ângulo em graus: ");
  scanf("%f", &angle);
  rad = angle * (pi / 180);
  printf("O ângulo em radianos é %.2f\n\n", rad);

  return 0;
}
