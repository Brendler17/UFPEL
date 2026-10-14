#include <stdio.h>

int main() {
  int minRange, maxRange, numberOfDividers = 0, sumPrime = 0;

  printf("Digite um intervalo de números inteiros (menor-maior): ");
  scanf("%d-%d", &minRange, &maxRange);

  for (int counterRange = minRange; counterRange <= maxRange; counterRange++) {
    for (int divider = 1; divider <= counterRange; divider++) {
      if (counterRange % divider == 0) {
        numberOfDividers++;
      }
    }

    if (numberOfDividers == 2) {
      sumPrime += counterRange;
    }

    numberOfDividers = 0;
  }

  printf("A soma entre os números primos contidos no intervalo de %d e %d é igual a %d.\n\n", minRange, maxRange, sumPrime);

  return 0;
}