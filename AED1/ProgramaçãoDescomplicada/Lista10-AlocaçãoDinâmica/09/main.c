#include <stdio.h>
#include <stdlib.h>

int main() {
  int* buffer = NULL;
  int number, countElements = 1;

  do {
    printf("Digite um número: ");
    scanf("%d", &number);

    if (number >= 0) {
      buffer = (int*)realloc(buffer, countElements * sizeof(int));
      if (buffer == NULL) {
        printf("Erro ao alocar memória!");
        return 1;
      }

      buffer[countElements - 1] = number;
      countElements++;
    }
  } while (number >= 0);

  if (buffer) {
    printf("\nO vetor digitado é: ");
    for (int counter = 0; counter < countElements - 1; counter++) {
      printf("%d ", buffer[counter]);
    }
  } else {
    printf("\nO vetor está vazio.");
  }

  printf("\n\n");

  free(buffer);

  return 0;
}