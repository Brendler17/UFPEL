#include <stdio.h>

int main() {
  int number, numberOfDividers = 0;

  printf("Digite um número (maior que 1): ");
  scanf("%d", &number);

  for (int counter = 1; counter <= number; counter++) {
    if (number % counter == 0) {
      numberOfDividers++;
    }
  }

  if (numberOfDividers == 2) {
    printf("O número %d é primo.\n\n", number);
  } else {
    printf("O número %d não é primo.\n\n", number);
  }

  return 0;
}
