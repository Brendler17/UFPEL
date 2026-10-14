#include <stdio.h>

void sum(int* adressA, int* adressB) { *adressA = *adressA + *adressB; }

int main() {
  int firstValue = 22, secondValue = 8;

  sum(&firstValue, &secondValue);

  printf("A soma dos valores é igual a %d e o segundo número é %d.\n\n", firstValue, secondValue);

  return 0;
}