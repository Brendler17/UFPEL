#include <math.h>
#include <stdio.h>

int main() {
  float height, weight, imc;

  printf("Digite a altura (em metros): ");
  scanf("%f", &height);
  printf("Digite o peso (em kg): ");
  scanf("%f", &weight);

  imc = weight / pow(height, 2);

  if (imc <= 18.5) {
    printf("Abaixo do peso.\n\n");

  } else if (imc >= 18.6 && imc < 25) {
    printf("Saudável.\n\n");

  } else if (imc >= 25 && imc < 30) {
    printf("Peso em excesso.\n\n");

  } else if (imc >= 30 && imc < 35) {
    printf("Obesidade Grau I.\n\n");

  } else if (imc >= 35 && imc < 40) {
    printf("Obesidade Grau II (Severa).\n\n");

  } else if (imc >= 40) {
    printf("Obesidade Grau III (Mórbida).\n\n");
  }

  return 0;
}