#include <stdio.h>

int main() {
  float salaryPerHour, grossSalary;
  int hoursWorkedInMonth;

  printf("Digite o valor da hora trabalhada: ");
  scanf("%f", &salaryPerHour);
  printf("Digite o total de horas trabalhadas no mês: ");
  scanf("%d", &hoursWorkedInMonth);
  grossSalary = salaryPerHour * hoursWorkedInMonth;
  printf("O valor a ser pago é R$%.2f\n\n", grossSalary + (grossSalary * 10 / 100));

  return 0;
}
