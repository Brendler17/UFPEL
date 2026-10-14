#include <stdio.h>

int main() {
  float price, newPrice;

  printf("Digite o valor antigo do produto: ");
  scanf("%f", &price);

  if (price < 50.0) {
    newPrice = price + (price * 5) / 100;
  }

  if (price >= 50 && price <= 100) {
    newPrice = price + (price * 10) / 100;
  }

  if (price > 100) {
    newPrice = price + (price * 15) / 100;
  }

  if (newPrice < 80) {
    printf("O novo preço do produto está BARATO e é R$%.2f\n\n", newPrice);
  }

  if (newPrice >= 80 && newPrice <= 120) {
    printf("O novo preço do produto está NORMAL e é R$%.2f\n\n", newPrice);
  }

  if (newPrice > 120 && newPrice <= 200) {
    printf("O novo preço do produto está CARO e é R$%.2f\n\n", newPrice);
  }

  if (newPrice > 200) {
    printf("O novo preço do produto está MUITO CARO e é R$%.2f\n\n", newPrice);
  }

  return 0;
}
