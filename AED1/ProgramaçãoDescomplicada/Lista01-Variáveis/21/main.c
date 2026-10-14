#include <stdio.h>

int main() {
  float lb, kg;

  printf("Digite a massa em libras: ");
  scanf("%f", &lb);
  kg = lb * 0.45;
  printf("A massa em quilogramas é %.2f\n\n", kg);

  return 0;
}