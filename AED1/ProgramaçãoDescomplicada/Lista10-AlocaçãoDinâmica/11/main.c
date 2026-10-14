#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int registration, yearOfBirth;
  char name[25];
} Student;

void formatString(char* string) {
  size_t len = strlen(string);
  if (len > 0 && string[len - 1] == '\n') {
    string[len - 1] = '\0';
  }
}

int main() {
  Student* buffer;
  size_t numberOfStudents;

  printf("Digite o número de alunos a serem cadastrados: ");
  scanf("%zu", &numberOfStudents);

  buffer = (Student*)malloc(numberOfStudents * sizeof(Student));
  if (buffer == NULL) {
    printf("Erro ao alocar memória!\n");
    return 1;
  }

  for (int counter = 0; counter < numberOfStudents; counter++) {
    getchar();
    printf("\nDigite as informações do %dº aluno:\n", counter + 1);
    printf("Digite o nome: ");
    fgets(buffer[counter].name, sizeof(buffer[counter].name), stdin);
    formatString(buffer[counter].name);
    printf("Digite o número de matrícula: ");
    scanf("%d", &buffer[counter].registration);
    printf("Digite o ano de nascimento: ");
    scanf("%d", &buffer[counter].yearOfBirth);
    printf("\n");
  }

  for (int counter = 0; counter < numberOfStudents; counter++) {
    printf("%dº Aluno:\n", counter + 1);
    printf("Nome: %s\n", buffer[counter].name);
    printf("Matrícula: %d\n", buffer[counter].registration);
    printf("Ano de Nascimento: %d\n", buffer[counter].yearOfBirth);
    printf("\n");
  }
  printf("\n\n");

  free(buffer);

  return 0;
}