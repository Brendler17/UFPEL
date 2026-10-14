#include <stdio.h>

int main() {
  float basePrice, discountedPrice, installmentPrice, cashCommission, installmentComission;

  printf("Digite o valor total: ");
  scanf("%f", &basePrice);
  discountedPrice = basePrice - (basePrice * 10 / 100);
  printf("Total a pagar com desconto R$%.2f\n", discountedPrice);
  installmentPrice = basePrice / 3;
  printf("Valor de cada parcela R$%.2f\n", installmentPrice);
  cashCommission = discountedPrice * 5 / 100;
  printf("Comissão na venda à vista R$%.2f\n", cashCommission);
  installmentComission = basePrice * 5 / 100;
  printf("Comissão na venda parcelada R$%.2f\n\n", installmentComission);

  return 0;
}
