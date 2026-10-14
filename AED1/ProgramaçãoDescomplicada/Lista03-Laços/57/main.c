#include <stdio.h>

int main() {
  int minRange, maxRange, primeCounter = 0;

  printf("Digite um intervalo de números inteiros (menor-maior): ");
  scanf("%d-%d", &minRange, &maxRange);

  int numberOfDividers = 0;

  for (int counterRange = minRange; counterRange <= maxRange; counterRange++) {
    for (int divider = 1; divider <= counterRange; divider++) {
      if (counterRange % divider == 0) {
        numberOfDividers++;
      }
    }

    if (numberOfDividers == 2) {
      primeCounter++;
    }

    numberOfDividers = 0;
  }

  printf("Existem %d números primos entre o intevalo de %d e %d.\n\n", primeCounter, maxRange, minRange);

  return 0;
}