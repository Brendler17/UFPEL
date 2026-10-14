#include <stdio.h>

int main() {
  float km, ms;

  printf("Digite a velocidade em quilômetros por hora: ");
  scanf("%f", &km);
  ms = km / 3.6;
  printf("A velocidade em metros por segundo é %.2f\n\n", ms);

  return 0;
}