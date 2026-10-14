#include <stdio.h>

int main() {
  float baseSalary, gratification, tax;

  printf("Digite o salário-base do funcionário: ");
  scanf("%f", &baseSalary);
  gratification = baseSalary + (baseSalary * 5 / 100);
  tax = baseSalary + (baseSalary * 7 / 100);
  printf("O sálario a ser pago é R$%.2f\n\n", baseSalary + gratification - tax);

  return 0;
}