#include <stdio.h>

int main() {
  int number, sum = 0;

  printf("Digite um número inteiro que não seja negativo: ");
  scanf("%d", &number);

  int sumCounter = 0;
  int numberCounter = 2;
  int numberOfDividers = 0;

  while (sumCounter < number) {
    for (int divider = numberCounter; divider != 0; divider--) {
      if (numberCounter % divider == 0) {
        numberOfDividers++;
      }
    }

    if (numberOfDividers == 2) {
      sum += numberCounter;
      sumCounter++;
    }

    numberCounter++;
    numberOfDividers = 0;
  }

  printf("A soma dos %d primeiros números primos é igual a %d.\n\n", number, sum);

  return 0;
}