#include <stdio.h>

int main() {
  int number;
  int numberCounter = 1;

  printf("Digite um número inteiro positivo: ");
  scanf("%d", &number);

  for (int lineCounter = 1; lineCounter <= number; lineCounter++) {
    for (int columnCounter = 0; columnCounter != lineCounter; columnCounter++) {
      printf("%d\t", numberCounter);
      numberCounter++;
    }
    printf("\n");
  }

  printf("\n");
  return 0;
}