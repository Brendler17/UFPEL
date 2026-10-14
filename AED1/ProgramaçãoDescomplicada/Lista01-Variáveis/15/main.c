#include <stdio.h>

static float pi = 3.14;

int main() {
  float rad, angle;

  printf("Digite o ângulo em radianos: ");
  scanf("%f", &rad);
  angle = rad * 180 / pi;
  printf("O ângulo em graus é %.2f\n\n", angle);

  return 0;
}