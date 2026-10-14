#include <stdio.h>

int main() {
  float m2, ac;

  printf("Digite a área em metros quadrados: ");
  scanf("%f", &m2);
  ac = m2 * 0.000247;
  printf("A área em acres é %f\n\n", ac);

  return 0;
}
