#include <stdio.h>

int main() {
  int intOne, intTwo;

  printf("Digite o valor da primeira variável: ");
  scanf("%d", &intOne);
  printf("Digite o valor da segunda variável: ");
  scanf("%d", &intTwo);

  if (&intOne > &intTwo) {
    printf("O endereço %p é maior, referente ao primeiro número %d.\n\n", (void *)&intOne, intOne);
  } else {
    printf("O endereço %p é maior, referente ao segundo número %d.\n\n", &intTwo, intTwo);
  }

  return 0;
}