#include <stdio.h>

int main() {
  float m2, ha;

  printf("Digite a área em metros quadrados: ");
  scanf("%f", &m2);
  ha = m2 * 0.0001;
  printf("A área em hectares é %.2f\n\n", ha);

  return 0;
}
