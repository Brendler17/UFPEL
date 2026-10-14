#include <stdio.h>

int main() {
  int number;
  int thousands, hundred, ten, unit;

  printf("Digite um número inteiro de até 4 digitos (1000-9999): ");
  scanf("%d", &number);

  if (number < 1000 || number > 9999) {
    printf("Número inválido!\n\n");
    return 1;
  }

  thousands = number / 1000;
  hundred = (number / 100) % 10;
  ten = (number / 10) % 10;
  unit = number % 10;

  printf("%d\n", thousands);
  printf("%d\n", hundred);
  printf("%d\n", ten);
  printf("%d\n\n", unit);

  return 0;
}
