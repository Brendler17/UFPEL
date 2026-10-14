#include <stdio.h>
#include <stdlib.h>

int main() {
  int lotteryNumbers[6], ticketNumbers[6], hits = 0;
  int *rightNumbers, *start;

  printf("Digite os 6 números da loteria: ");
  for (int counter = 0; counter < 6; counter++) {
    scanf("%d", &lotteryNumbers[counter]);
  }

  printf("Digite os 6 números do bilhete: ");
  for (int counter = 0; counter < 6; counter++) {
    scanf("%d", &ticketNumbers[counter]);
  }

  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      if (lotteryNumbers[i] == ticketNumbers[j]) {
        hits++;
        break;
      }
    }
  }

  rightNumbers = (int *)malloc(hits * sizeof(int));
  if (rightNumbers == NULL) {
    printf("Erro ao alocar memória!");
    return 1;
  }

  start = rightNumbers;

  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      if (lotteryNumbers[i] == ticketNumbers[j]) {
        *rightNumbers = ticketNumbers[j];
        rightNumbers++;
      }
    }
  }

  rightNumbers = start;

  printf("\nOs números sorteados foram: ");
  for (int counter = 0; counter < 6; counter++) {
    printf("%d ", lotteryNumbers[counter]);
  }

  if (hits > 0) {
    printf("\nOs números corretos foram: ");
    for (int counter = 0; counter < hits; counter++) {
      printf("%d ", rightNumbers[counter]);
    }
  } else {
    printf("Nenhum número foi acertado.\n\n");
  }

  printf("\n\n");

  free(start);

  return 0;
}