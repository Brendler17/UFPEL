#include <stdio.h>

int sumOfDouble(int* firstValue, int* secoundValue) {
  *firstValue *= 2;
  *secoundValue *= 2;

  return *firstValue + *secoundValue;
}

int main() {
  int firstValue, secondValue, result;

  printf("Digite dois valores inteiros (separados por espaço): ");
  scanf("%d %d", &firstValue, &secondValue);

  result = sumOfDouble(&firstValue, &secondValue);
  printf("O dobro de %d é %d, o dobro de %d é %d e a soma do dobro dos dois números é %d.\n\n", firstValue / 2, firstValue,
         secondValue / 2, secondValue, result);

  return 0;
}