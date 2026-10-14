#include <math.h>
#include <stdio.h>

static float PI = 3.141592;

int main() {
  float radius, height, volume;

  printf("Digite o raio de um cilindro circular: ");
  scanf("%f", &radius);
  printf("Digite a altura de um cilindro circular: ");
  scanf("%f", &height);
  volume = PI * pow(radius, 2) * height;
  printf("O volume do cilindro é %.2f\n\n", volume);

  return 0;
}