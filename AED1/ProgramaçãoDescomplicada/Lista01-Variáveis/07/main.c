#include <stdio.h>

int main() {
  float fahrenheit, celsius;

  printf("Digite a temperatura em Fahrenheit: ");
  scanf("%f", &fahrenheit);
  celsius = 5.0 * (fahrenheit - 32.0) / 9.0;
  printf("A temperatura em Celsius é: %.2f\n\n", celsius);

  return 0;
}