#include <stdio.h>

int main() {
  float km, mi;

  printf("Digite a distância em quilômetros: ");
  scanf("%f", &km);
  mi = km / 1.61;
  printf("A distância em milhas é %.2f\n\n", mi);

  return 0;
}