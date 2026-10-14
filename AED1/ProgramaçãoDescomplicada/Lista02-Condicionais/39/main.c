#include <stdio.h>

int main() {
  float currentSalary, bonus, reajustment;
  int yearsWorked;

  printf("Digite o salário atual do funcionário: ");
  scanf("%f", &currentSalary);
  printf("Digite o tempo trabalhado do funcionário: ");
  scanf("%d", &yearsWorked);

  if (currentSalary <= 500) {
    reajustment = 0.25;

  } else if (currentSalary > 500 && currentSalary <= 1000) {
    reajustment = 0.20;

  } else if (currentSalary > 1000 && currentSalary <= 1500) {
    reajustment = 0.15;

  } else if (currentSalary > 1500 && currentSalary <= 2000) {
    reajustment = 0.10;

  } else if (currentSalary > 2000) {
    reajustment = 0.0;
  }

  if (yearsWorked < 1) {
    bonus = 0.0;
  } else if (yearsWorked >= 1 && yearsWorked <= 3) {
    bonus = 100.0;

  } else if (yearsWorked >= 4 && yearsWorked <= 6) {
    bonus = 200.0;

  } else if (yearsWorked >= 7 && yearsWorked <= 10) {
    bonus = 300.0;

  } else if (yearsWorked > 10) {
    bonus = 500.0;
  }

  if (reajustment != 0 || bonus != 0) {
    currentSalary = currentSalary + (currentSalary * reajustment) + bonus;
    printf("O salário reajustado do funcionário é R$%.2f\n\n", currentSalary);

  } else {
    printf("O funcionário não possui direito a reajuste.\n\n");
  }

  return 0;
}
