#include <stdio.h>

int main() {
  float grades[4], average;

  for (int count = 0; count < 4; count++) {
    printf("Digite uma nota: ");
    scanf("%f", &grades[count]);
    average += grades[count];
  }

  printf("A média aritmética das notas é %.2f\n\n", average / 4);

  return 0;
}