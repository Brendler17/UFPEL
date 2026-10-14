#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isVowel(char letter) {
  char vowels[] = "AEIOUaeiou";
  return (strchr(vowels, letter) != NULL);
}

int main() {
  char *string;
  int size;

  printf("Digite o tamanho máximo da string: ");
  scanf("%d", &size);
  getchar();

  string = (char *)malloc((size + 1) * sizeof(char));
  if (string == NULL) {
    printf("Erro ao alocar memória!");
    return 1;
  }

  printf("Digite uma string: ");
  fgets(string, size, stdin);

  size_t len = strlen(string);
  if (len > 0 && string[len - 1] == '\n') {
    string[len - 1] = '\0';
  }

  printf("A string sem vogais é: ");
  for (size_t counter = 0; counter < len; counter++) {
    if (!isVowel(string[counter])) {
      printf("%c", string[counter]);
    }
  }
  printf("\n\n");

  free(string);

  return 0;
}