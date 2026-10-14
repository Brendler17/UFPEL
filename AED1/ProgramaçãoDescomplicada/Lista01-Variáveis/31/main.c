#include <stdio.h>

int main() {
  int number;

  printf("Digite um número inteiro: ");
  scanf("%d", &number);
  printf("O sucessor do número digitado é %d e o seu antecessor é %d.\n\n", number + 1, number - 1);

  return 0;
}