#include <math.h>
#include <stdio.h>

static float PI = 3.141592;

int main() {
  float radius;

  printf("Digite o raio de um círculo: ");
  scanf("%f", &radius);
  printf("A área do círculo é %.2f\n\n", PI * pow(radius, 2));

  return 0;
}