#include <math.h>
#include <stdio.h>

int main() {
  int opposite, adjacent;
  float hypotenuse;

  printf("Digite o valor do primeiro cateto: ");
  scanf("%d", &opposite);
  printf("Digite o valor do segundo cateto: ");
  scanf("%d", &adjacent);
  hypotenuse = sqrt((pow(opposite, 2) + pow(adjacent, 2)));
  printf("O valor da hipotenusa é %.2f\n\n", hypotenuse);

  return 0;
}