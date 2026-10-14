#include <stdio.h>

int main() {
  int age, currentYear;

  printf("Digite sua idade: ");
  scanf("%d", &age);
  printf("Digite o ano atual: ");
  scanf("%d", &currentYear);

  printf("O ano do seu nascimento é %d.\n\n", currentYear - age);

  return 0;
}
