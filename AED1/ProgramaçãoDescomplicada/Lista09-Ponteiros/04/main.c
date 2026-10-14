#include <stdio.h>

void swapValues(int* adressA, int* adressB) {
  int temp = *adressA;
  *adressA = *adressB;
  *adressB = temp;
}

int main() {
  int firstValue, secondValue;

  printf("Digite dois valores (separados por espaço): ");
  scanf("%d %d", &firstValue, &secondValue);

  swapValues(&firstValue, &secondValue);

  printf("Valores invertidos: %d e %d.\n\n", firstValue, secondValue);

  return 0;
}