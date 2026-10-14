#include <stdio.h>

int main() {
  float ha, m2;

  printf("Digite a área em hectares: ");
  scanf("%f", &ha);
  m2 = ha * 10000;
  printf("A área em metros quadrados é %.0f\n\n", m2);

  return 0;
}
