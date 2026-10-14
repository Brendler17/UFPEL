#include <stdio.h>

int main() {
  float mi, km;

  printf("Digite a distância em milhas: ");
  scanf("%f", &mi);
  km = mi * 1.61;
  printf("A distância em quilômetros é %.2f\n\n", km);

  return 0;
}