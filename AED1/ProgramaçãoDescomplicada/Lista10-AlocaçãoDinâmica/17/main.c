#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int *buffer;
  int counter = 0;
  size_t size = 10;

  buffer = (int *)malloc(size * sizeof(int));
  if (buffer == NULL) {
    printf("\nErro ao alocar memória!\n\n");
    return 1;
  }

  printf("Digite um valor (0 para sair): ");
  while (scanf("%d", &buffer[counter]) == 1 && buffer[counter] != 0) {
    counter++;

    if (counter >= size) {
      size_t oldSize = size;
      size += 10;

      int *auxBuffer = (int *)malloc(size * sizeof(int));
      if (auxBuffer == NULL) {
        printf("\nErro ao alocar memória!\n\n");
        free(buffer);
        return 1;
      }

      memcpy(auxBuffer, buffer, oldSize * sizeof(int));
      free(buffer);

      buffer = auxBuffer;
    }

    printf("Digite um valor: ");
  }

  printf("\nOs valores digitados foram: ");
  for (size_t arrayCounter = 0; arrayCounter < counter; arrayCounter++) {
    printf("%d ", buffer[arrayCounter]);
  }

  printf("\n\n");
  free(buffer);

  return 0;
}