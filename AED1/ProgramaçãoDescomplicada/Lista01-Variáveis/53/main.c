#include <stdio.h>

int main() {
  float length, width, pricePerMeter, perimeter, totalPrice;

  printf("Digite o comprimento e largura de um terreno (separados por espaço): ");
  scanf("%f %f", &length, &width);
  printf("Digite o preço por metro de tela: ");
  scanf("%f", &pricePerMeter);

  perimeter = 2 * (length + width);
  totalPrice = perimeter * pricePerMeter;

  printf("O custo para cercar esse terreno será R$%.2f\n\n", totalPrice);

  return 0;
}