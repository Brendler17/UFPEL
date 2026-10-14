#include <stdio.h>

void biggestNumberInArray(int* array, int size, int* biggestNumber, int* occurrenceNumber) {
  *biggestNumber = array[0];
  *occurrenceNumber = 0;

  for (int counter = 0; counter < size; counter++) {
    if (array[counter] > *biggestNumber) {
      *biggestNumber = array[counter];
      *occurrenceNumber = 1;
    } else if (array[counter] == *biggestNumber) {
      *occurrenceNumber += 1;
    }
  }
}

int main() {
  int array[10] = {22, 13, 7, 8, 17, 22, 7, 11, 22, 17};
  int size = sizeof(array) / sizeof(array[0]);
  int biggestNumber, occurrenceNumber;

  biggestNumberInArray(array, size, &biggestNumber, &occurrenceNumber);

  printf("O maior número do array é: %d,", biggestNumber);
  printf(" e ele ocorre %d vezes.\n\n", occurrenceNumber);

  return 0;
}