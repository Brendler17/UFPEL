#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void removeTrailingNewLine(char *string);

void showMenu() {
  printf("\n-----------------MENU-----------------\n");
  printf("1 - Gravar um nome em uma linha\n");
  printf("2 - Apagar um nome em uma linha\n");
  printf("3 - Alterar um nome\n");
  printf("4 - Apagar um nome\n");
  printf("5 - Buscar o nome em uma linha\n");
  printf("6 - Listar todos os nomes\n");
  printf("0 - Sair\n");
}

void insertName(char **names, size_t numberOfNames, size_t numberOfCharacters) {
  size_t userOptionLine;

  printf("\nDigite a linha em que deseja inserir o nome (0 a %zu): ", numberOfNames - 1);
  if (scanf("%zu", &userOptionLine) != 1 || userOptionLine < 0 || userOptionLine >= numberOfNames) {
    system("clear");
    printf("\nValor inválido!\n");
    return;
  }

  if (names[userOptionLine][0] == '\0') {
    getchar();
    printf("Digite o nome: ");
    fgets(names[userOptionLine], numberOfCharacters, stdin);
    removeTrailingNewLine(names[userOptionLine]);
    system("clear");
    printf("\nNome inserido com sucesso!\n");
  } else {
    system("clear");
    printf("\nA linha informada já contém um nome!\n");
  }
}

void removeNameByPosition(char **names, size_t numberOfNames) {
  size_t userOptionLine;

  printf("\nDigite a linha em que deseja remover o nome (0 a %zu): ", numberOfNames - 1);
  if (scanf("%zu", &userOptionLine) != 1 || userOptionLine < 0 || userOptionLine >= numberOfNames) {
    system("clear");
    printf("\nValor inválido!\n");
    return;
  }

  if (names[userOptionLine][0] != '\0') {
    size_t nameSize = strlen(names[userOptionLine]);
    for (size_t character = 0; character < nameSize; character++) {
      names[userOptionLine][character] = '\0';
    }
    system("clear");
    printf("\nNome removido com sucesso!\n");
  } else {
    system("clear");
    printf("\nA linha informada não contém nenhum nome!\n");
  }
}

void changeName(char **names, size_t numberOfNames, size_t numberOfCharacters) {
  char userOptionName[30];
  int namesEqual = 0;

  getchar();
  printf("\nDigite o nome que deseja buscar: ");
  fgets(userOptionName, numberOfCharacters, stdin);
  removeTrailingNewLine(userOptionName);

  for (size_t line = 0; line < numberOfNames; line++) {
    if (strcmp(userOptionName, names[line]) == 0) {
      namesEqual = 1;
      printf("Digite o novo nome: ");
      fgets(names[line], numberOfCharacters, stdin);
      removeTrailingNewLine(names[line]);
      system("clear");
      printf("\nO nome foi alterado com sucesso!\n");
      break;
    }
  }

  if (!namesEqual) {
    system("clear");
    printf("\nO nome informado não foi encontrado!\n");
  }
}

void removeNameByName(char **names, size_t numberOfNames, size_t numberOfCharacters) {
  char userOptionName[30];
  int namesEqual = 0;

  getchar();
  printf("\nDigite o nome que deseja apagar: ");
  fgets(userOptionName, numberOfCharacters, stdin);
  removeTrailingNewLine(userOptionName);

  for (size_t line = 0; line < numberOfNames; line++) {
    if (strcmp(userOptionName, names[line]) == 0) {
      namesEqual = 1;
      for (size_t character = 0; character < numberOfCharacters; character++) {
        names[line][character] = '\0';
      }
      system("clear");
      printf("\nNome removido com sucesso!\n");
      break;
    }
  }

  if (!namesEqual) {
    system("clear");
    printf("\nO nome informado não foi encontrado!\n");
  }
}

void getName(char **names, size_t numberOfNames) {
  size_t userOptionLine;

  printf("\nDigite a linha em que deseja buscar o nome (0 a %zu): ", numberOfNames - 1);
  if (scanf("%zu", &userOptionLine) != 1 || userOptionLine < 0 || userOptionLine >= numberOfNames) {
    system("clear");
    printf("\nValor inválido!\n");
    return;
  }

  if (names[userOptionLine][0] != '\0') {
    system("clear");
    printf("\nO nome na linha %zu é %s.\n", userOptionLine, names[userOptionLine]);
  } else {
    system("clear");
    printf("\nA linha informada não contém nenhum nome!\n");
  }
}

void printAllNames(char **names, size_t numberOfNames) {
  system("clear");
  for (size_t line = 0; line < numberOfNames; line++) {
    printf("%s\n", names[line]);
  }
}

void freeMatrix(char **matrix, size_t numberOfLines) {
  if (matrix != NULL) {
    for (size_t line = 0; line < numberOfLines; line++) {
      free(matrix[line]);
    }

    free(matrix);
  }
}

void removeTrailingNewLine(char *string) {
  size_t len = strlen(string);
  if (len > 0 && string[len - 1] == '\n') {
    string[len - 1] = '\0';
  }
}

int main() {
  char **names;
  size_t numberOfNames, numberOfCharacters = 30;
  int option;

  printf("Informe a quantidade máxima de nomes a serem armazenados: ");
  if (scanf("%zu", &numberOfNames) != 1 || numberOfNames <= 0) {
    printf("\nValor inválido!\n\n");
    return 1;
  }

  names = (char **)calloc(numberOfNames, sizeof(char *));
  if (names == NULL) {
    printf("\nErro ao alocar memória!\n\n");
    return 1;
  }

  for (size_t line = 0; line < numberOfNames; line++) {
    names[line] = (char *)calloc(numberOfCharacters, sizeof(char));
    if (names[line] == NULL) {
      printf("\nErro ao alocar memória!\n\n");
      freeMatrix(names, line);
      return 1;
    }
  }

  do {
    showMenu();
    printf("Digite sua opção: ");
    scanf("%d", &option);

    switch (option) {
      case 1:
        insertName(names, numberOfNames, numberOfCharacters);
        break;
      case 2:
        removeNameByPosition(names, numberOfNames);
        break;
      case 3:
        changeName(names, numberOfNames, numberOfCharacters);
        break;
      case 4:
        removeNameByName(names, numberOfNames, numberOfCharacters);
        break;
      case 5:
        getName(names, numberOfNames);
        break;
      case 6:
        printAllNames(names, numberOfNames);
        break;
      case 0:
        system("clear");
        printf("Saindo...\n\n");
        break;
      default:
        printf("Digite uma opção válida!\n");
        break;
    }
  } while (option != 0);

  freeMatrix(names, numberOfNames);

  return 0;
}