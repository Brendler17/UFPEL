#include <stdio.h>

int main() {
  float ms, km;

  printf("Digite a velocidade em metros por segundo: ");
  scanf("%f", &ms);
  km = ms * 3.6;
  printf("A velocidade em quilômetros por hora é %.2f\n\n", km);

  return 0;
}