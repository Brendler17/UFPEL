#include <stdio.h>

int negatives(float* array, int size) {
  int numberOfNegatives = 0;

  for (int counter = 0; counter < size; counter++) {
    if (array[counter] < 0.0) {
      numberOfNegatives++;
    }
  }

  return numberOfNegatives;
}

int main() {
  float array[10] = {1.1, -5.7, 3.3, 4.4, 5.5, -6.6, 7.7, 8.8, -9.9, 10.10};
  int size = sizeof(array) / sizeof(array[0]);
  int numberOfNegatives;

  numberOfNegatives = negatives(array, size);

  printf("A quantidade de números negativos no vetor é: %d\n\n", numberOfNegatives);

  return 0;
}