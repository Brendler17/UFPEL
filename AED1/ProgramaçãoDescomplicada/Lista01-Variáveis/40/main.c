#include <stdio.h>

int main() {
  float salaryPerDay = 30.00, grossSalary;
  int daysWorked;

  printf("Digite o número de dias trabalhados: ");
  scanf("%d", &daysWorked);
  grossSalary = salaryPerDay * daysWorked;
  printf("A quantia que deverá ser paga é R$%.2f\n\n", grossSalary - (grossSalary * 8 / 100));

  return 0;
}
