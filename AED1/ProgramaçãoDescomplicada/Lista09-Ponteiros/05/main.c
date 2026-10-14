#include <stdio.h>

void swapValues(int* adressA, int* adressB) {
  if (*adressB > *adressA) {
    int temp = *adressA;
    *adressA = *adressB;
    *adressB = temp;
  }
}

int main() {
  int firstValue, secondValue;

  printf("Digite dois números (separados por espaço): ");
  scanf("%d %d", &firstValue, &secondValue);

  swapValues(&firstValue, &secondValue);

  printf("O valor %d é maior que %d.\n\n", firstValue, secondValue);

  return 0;
}