#include <stdio.h>

int main() {
  float saleValue, commission;

  printf("Digite o valor da venda: ");
  scanf("%f", &saleValue);

  if (saleValue > 0 && saleValue < 20000.00) {
    commission = 400.00 + (saleValue * 14 / 100);
    printf("A comissão paga ao vendedor é R$%.2f\n\n", commission);
  }

  if (saleValue >= 20000.00 && saleValue < 40000.00) {
    commission = 500.00 + (saleValue * 14 / 100);
    printf("A comissão paga ao vendedor é R$%.2f\n\n", commission);
  }

  if (saleValue >= 40000.00 && saleValue < 60000.00) {
    commission = 550.00 + (saleValue * 14 / 100);
    printf("A comissão paga ao vendedor é R$%.2f\n\n", commission);
  }

  if (saleValue >= 60000.00 && saleValue < 80000.00) {
    commission = 600.00 + (saleValue * 14 / 100);
    printf("A comissão paga ao vendedor é R$%.2f\n\n", commission);
  }

  if (saleValue >= 80000.00 && saleValue < 100000.00) {
    commission = 650.00 + (saleValue * 14 / 100);
    printf("A comissão paga ao vendedor é R$%.2f\n\n", commission);
  }

  if (saleValue >= 100000.00) {
    commission = 700.00 + (saleValue * 16 / 100);
    printf("A comissão paga ao vendedor é R$%.2f\n\n", commission);
  }

  return 0;
}
