#include <stdio.h>

int orderValues(int* adressA, int* adressB, int* adressC) {
  if (*adressA > *adressB) {
    int temp = *adressA;
    *adressA = *adressB;
    *adressB = temp;
  }
  if (*adressA > *adressC) {
    int temp = *adressA;
    *adressA = *adressC;
    *adressC = temp;
  }
  if (*adressB > *adressC) {
    int temp = *adressB;
    *adressB = *adressC;
    *adressC = temp;
  }

  if (*adressA == *adressB && *adressA == *adressC) {
    return 1;
  } else {
    return 0;
  }
}

int main() {
  int firstValue, secondValue, thirdValue;

  printf("Digite 3 valores: ");
  scanf("%d %d %d", &firstValue, &secondValue, &thirdValue);

  orderValues(&firstValue, &secondValue, &thirdValue);

  printf("Os valores ordenados: ");
  printf("%d  %d  %d\n\n", firstValue, secondValue, thirdValue);

  return 0;
}