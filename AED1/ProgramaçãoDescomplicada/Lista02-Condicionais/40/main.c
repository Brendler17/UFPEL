#include <stdio.h>

int main() {
  float factoryCost, consumerCost = 0.0;

  printf("Digite o custo de fábrica: ");
  scanf("%f", &factoryCost);

  if (factoryCost < 12000.00) {
    consumerCost = factoryCost + (factoryCost * 0.05);

  } else if (factoryCost >= 12000.00 && factoryCost <= 25000.00) {
    consumerCost = factoryCost + (factoryCost * 0.10) + (factoryCost * 0.15);

  } else if (factoryCost > 25000.00) {
    consumerCost = factoryCost + (factoryCost * 0.15) + (factoryCost * 0.20);
  }

  printf("O custo para o consumidor será de R$%.2f\n\n", consumerCost);

  return 0;
}