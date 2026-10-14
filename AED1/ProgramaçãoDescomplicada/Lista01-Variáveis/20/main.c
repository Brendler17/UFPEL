#include <stdio.h>

int main() {
  float kg, lb;

  printf("Digite a massa em quilogramas: ");
  scanf("%f", &kg);
  lb = kg / 0.45;
  printf("A massa é libras é %.4f\n\n", lb);

  return 0;
}