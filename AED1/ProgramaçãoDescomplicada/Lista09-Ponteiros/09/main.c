#include <stdio.h>

int main() {
  float matrix[3][3];

  for (int counterLine = 0; counterLine < 3; counterLine++) {
    for (int counterColumn = 0; counterColumn < 3; counterColumn++) {
      printf("O endereço na posição %d%d é: %p\n", counterLine, counterColumn, (void *)&matrix[counterLine][counterColumn]);
    }
  }
  printf("\n");

  return 0;
}