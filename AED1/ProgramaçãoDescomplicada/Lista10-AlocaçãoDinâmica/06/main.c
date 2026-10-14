#include <stdio.h>
#include <stdlib.h>

void showMenu() {
  printf("\n------- MENU -------\n");
  printf("1 - Inserir valor\n");
  printf("2 - Consultar valor\n");
  printf("0 - Sair\n");
  printf("--------------------\n");
  printf("Digite sua opção: ");
}

void initBuffer(int *buffer, int numElements) {
  for (int counter = 0; counter < numElements; counter++) {
    *(buffer + counter) = 0;
  }
}

void insertValue(int *buffer, int number, int position) { *(buffer + position) = number; }

void consultValue(int *buffer, int position) { printf("O valor na posição %d é: %d.\n", position, *(buffer + position)); }

int main() {
  int *buffer;
  int size, numElements, option, number, position;

  do {
    printf("Informe a quantidade de bytes a serem alocados ");
    printf("(o valor deve ser múltiplo de %d): ", (int)sizeof(int));
    scanf("%d", &size);
  } while (size <= 0 || size % sizeof(int) != 0);

  numElements = size / sizeof(int);

  buffer = (int *)malloc(size);
  if (buffer == NULL) {
    printf("Erro ao alocar memória!");
    return 1;
  }

  initBuffer(buffer, numElements);

  do {
    showMenu();
    scanf("%d", &option);

    switch (option) {
      case 1:
        printf("Digite o número a ser inserido: ");
        scanf("%d", &number);

        do {
          printf("Digite em que posição deseja inserir (0-%d): ", numElements - 1);
          scanf("%d", &position);
        } while (position < 0 || position >= numElements);

        insertValue(buffer, number, position);
        break;
      case 2:
        do {
          printf("Digite qual posição deseja consultar (0-%d): ", numElements - 1);
          scanf("%d", &position);
        } while (position < 0 || position >= numElements);

        consultValue(buffer, position);
        break;

      case 0:
        printf("Saindo...\n\n");
        break;

      default:
        printf("Digite uma opção válida!");
        break;
    }
  } while (option != 0);

  free(buffer);

  return 0;
}