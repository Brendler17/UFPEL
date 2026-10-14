#include <math.h>
#include <stdio.h>

#define M_PI 3.14159265358979323846

void calc_esfera(float R, float *area, float *volume) {
  *area = 4 * M_PI * pow(R, 2);
  *volume = (4.0 / 3.0) * M_PI * pow(R, 3);
}

int main() {
  float radius, area, volume;

  printf("Informe o raio da esfera: ");
  scanf("%f", &radius);

  calc_esfera(radius, &area, &volume);

  printf("A área da superfície da esfera é %.2f\n", area);
  printf("O volume da esfera é %.2f\n", volume);

  return 0;
}