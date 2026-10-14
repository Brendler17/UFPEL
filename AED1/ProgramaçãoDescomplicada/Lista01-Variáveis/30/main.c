#include <stdio.h>

int main() {
  float real, dollar, price;

  printf("Digite o valor em reais: ");
  scanf("%f", &real);
  printf("Digite a cotação do dólar: ");
  scanf("%f", &price);
  dollar = real / price;
  printf("O valor corresponde em dólares é $%.2f\n\n", dollar);

  return 0;
}