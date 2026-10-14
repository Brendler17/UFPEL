#include <stdio.h>

int main() {
  int intOne = 17, intTwo, *adressOne, *adressTwo;

  adressOne = &intOne;
  adressTwo = &intTwo;

  if (adressOne > adressTwo) {
    printf("O endereço %p é maior que o endereço %p.\n\n", adressOne, adressTwo);
  } else {
    printf("O endereço %p é maior que o endereço %p.\n\n", adressTwo, adressOne);
  }

  return 0;
}