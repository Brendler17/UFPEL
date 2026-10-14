#include <stdio.h>

int main() {
  float celsius, kelvin;

  printf("Digite a temperatura em Celsius: ");
  scanf("%f", &celsius);
  kelvin = celsius + 273.15;
  printf("A temperatura em Kelvin é %.2f\n\n", kelvin);

  return 0;
}