#include <stdio.h>

int main() {
  char letter;

  printf("Digite uma letra maiúscula: ");
  scanf("%c", &letter);
  letter = letter + 32;
  printf("A letra convertida: %c\n\n", letter);

  return 0;
}