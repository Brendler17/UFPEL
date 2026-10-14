#include <stdio.h>

int main() {
  float note;
  int fouls;

  printf("Digite a nota do aluno: ");
  scanf("%f", &note);
  printf("Digite o número de faltas do aluno: ");
  scanf("%d", &fouls);

  if (note < 3.9) {
    printf("O conceito do aluno é E.\n\n");
  }

  if (note >= 4.0 && note <= 4.9) {
    if (fouls <= 20) {
      printf("O conceito do aluno é D.\n\n");
    }
    if (fouls > 20) {
      printf("O conceito do aluno é E.\n\n");
    }
  }

  if (note >= 5.0 && note <= 7.4) {
    if (fouls <= 20) {
      printf("O conceito do aluno é C.\n\n");
    }
    if (fouls > 20) {
      printf("O conceito do aluno é D.\n\n");
    }
  }

  if (note >= 7.5 && note <= 8.9) {
    if (fouls <= 20) {
      printf("O conceito do aluno é B.\n\n");
    }
    if (fouls > 20) {
      printf("O conceito do aluno é C.\n\n");
    }
  }

  if (note >= 9.0 && note <= 10.0) {
    if (fouls <= 20) {
      printf("O conceito do aluno é A.\n\n");
    }
    if (fouls > 20) {
      printf("O conceito do aluno é B.\n\n");
    }
  }

  return 0;
}
