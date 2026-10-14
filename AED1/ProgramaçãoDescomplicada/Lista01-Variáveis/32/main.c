#include <stdio.h>

int main() {
  int number;

  printf("Digite um número: ");
  scanf("%d", &number);
  printf("A soma entre o sucessor do seu triplo com o antecessor do seu dobro é %d.\n\n", (number * 3 + 1) + (number * 2 - 1));

  return 0;
}
