#include <stdio.h>

int sumOfArrays(int* firstArray, int* secondArray, int* result, int sizeOne, int sizeTwo) {
  if (sizeOne == sizeTwo) {
    int* endArray = firstArray + sizeOne;

    while (firstArray < endArray) {
      *result = *firstArray + *secondArray;

      result++;
      firstArray++;
      secondArray++;
    }

    return 1;

  } else {
    return 0;
  }
}

int main() {
  int firstArray[] = {1, 2, 3};
  int secondArray[] = {1, 2, 3};
  int sizeOne = sizeof(firstArray) / sizeof(firstArray[0]);
  int sizeTwo = sizeof(secondArray) / sizeof(secondArray[0]);
  int sumArray[sizeOne];
  int result;

  result = sumOfArrays(firstArray, secondArray, sumArray, sizeOne, sizeTwo);

  if (result == 1) {
    printf("O resultado da soma dos arrays é: \n");
    for (int counter = 0; counter < sizeOne; counter++) {
      printf("%d\t", sumArray[counter]);
    }
    printf("\n\n");
  } else {
    printf("Não foi possível somar os arrays.\n\n");
  }

  return 0;
}