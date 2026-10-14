#include <stdio.h>

int getBiggestNumber(int* array, int size) {
  int biggestNumber = 0;

  for (int counter = 0; counter < size; counter++) {
    if (array[counter] > biggestNumber) {
      biggestNumber = array[counter];
    }
  }

  return biggestNumber;
}

int main() {
  int size, numbersPerLine, biggestNumber, numbers;

  printf("Digite a quantidade de números a serem digitados: ");
  scanf("%d", &size);

  int array[size];

  printf("Digite os números: ");
  for (int counter = 0; counter < size; counter++) {
    scanf("%d", &array[counter]);
  }

  printf("\nDigite quantos números serão mostrados por linha: ");
  scanf("%d", &numbersPerLine);

  numbers = numbersPerLine;
  printf("\n");

  for (int counter = 0; counter < size; counter++) {
    if (numbersPerLine == 0) {
      printf("\n");
      printf("%d\t", array[counter]);
      numbersPerLine = numbers - 1;
    } else {
      printf("%d\t", array[counter]);
      numbersPerLine--;
    }
  }

  biggestNumber = getBiggestNumber(array, size);

  printf("\n\nO maior elemento é %d.\n\n", biggestNumber);

  return 0;
}