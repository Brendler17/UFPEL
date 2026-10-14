#include <stdio.h>

int main() {
  float price;

  printf("Digite o valor de um produto: ");
  scanf("%f", &price);
  printf("O valor do produto com o desconto é R$%.2f\n\n", price - ((price * 12) / 100));

  return 0;
}
