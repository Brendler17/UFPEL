#include <stdio.h>

int main() {
  int number, sum = 0, counter = 0, evenSum = 0, evenCounter = 0, biggest, smallest;

  printf("Digite os números (0 para sair):\n");
  scanf("%d", &number);
  biggest = smallest = number;

  while (number != 0) {
    sum += number;
    counter++;

    if (number > biggest) {
      biggest = number;
    }
    if (number < smallest) {
      smallest = number;
    }

    if (number % 2 == 0) {
      evenSum += number;
      evenCounter++;
    }

    scanf("%d", &number);
  }

  printf("\n---------------Resultados---------------");
  printf("\nA soma dos número digitados é: %d.\n", sum);
  printf("A quantidade de número digitados é: %d.\n", counter);
  printf("A média dos número digitados é: %.1f.\n", (float)sum / counter);
  printf("O maior número digitado é: %d.\n", biggest);
  printf("O menor número digitado é: %d.\n", smallest);
  printf("A média dos números pares digitados é: %.1f.\n\n", evenCounter ? (float)evenSum / evenCounter : 0.0);

  return 0;
}