#include <stdio.h>

int main() {
  float award = 780000.00;

  printf("O primeiro ganhador ficará com R$%.2f\n", award * 46 / 100);
  printf("O segundo ganhador ficará com R$%.2f\n", award * 32 / 100);
  printf("O terceiro ganhador ficará com R$%.2f\n\n", award * (100 - 46 - 32) / 100);

  return 0;
}
