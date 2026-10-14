#include <stdio.h>

void getExtremeNumbers(int* array, int size, int* min, int* max) {
  *min = __INT_MAX__;
  *max = -__INT_MAX__ - 1;

  for (int counter = 0; counter < size; counter++) {
    if (array[counter] > *max) {
      *max = array[counter];
    }
    if (array[counter] < *min) {
      *min = array[counter];
    }
  }
}

int main() {
  int size;
  int min, max;

  printf("Digite a quantidade de números a serem digitados: ");
  scanf("%d", &size);

  int array[size];

  printf("Digite os números: ");
  for (int counter = 0; counter < size; counter++) {
    scanf("%d", &array[counter]);
  }

  getExtremeNumbers(array, size, &min, &max);

  printf("\nO menor número do vetor é: %d\n", min);
  printf("O maior número do vetor é: %d\n\n", max);

  return 0;
}