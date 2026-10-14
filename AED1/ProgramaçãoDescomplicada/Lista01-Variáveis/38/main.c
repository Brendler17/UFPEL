#include <stdio.h>

int main() {
  float salary;

  printf("Digite o sálario do funcionário: ");
  scanf("%f", &salary);
  printf("O salário com aumento é R$%.2f\n\n", salary + (salary * 25 / 100));

  return 0;
}
