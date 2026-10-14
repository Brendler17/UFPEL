#include <stdio.h>

int main() {
  float ac, m2;

  printf("Digite a área em acres: ");
  scanf("%f", &ac);
  m2 = ac * 4048.58;
  printf("A área em metros quadrados é %.2f\n\n", m2);

  return 0;
}
