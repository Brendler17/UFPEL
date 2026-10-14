#include <stdio.h>

static int currentYear = 2003;

int main() {
  float salary = 2000.00;
  float percentageIncrease = 0.015;

  for (int year = 1996; year <= currentYear; year++) {
    salary += (salary * percentageIncrease);
    percentageIncrease *= 2.00;
  }

  printf("O salário atual do funcionário no ano de %d, é R$%.2f\n\n", currentYear, salary);

  return 0;
}
