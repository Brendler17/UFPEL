#include <math.h>
#include <stdio.h>

int main() {
  int numbers[3], sum;

  for (int count = 0; count < 3; count++) {
    printf("Digite um número: ");
    scanf("%d", &numbers[count]);
    sum += pow(numbers[count], 2);
  }

  printf("A soma dos quadrados dos valores é %d\n\n", sum);

  return 0;
}
