#include <stdio.h>

int main() {
  float bankWithdrawal;
  int note100, note50 = 0, note20 = 0, note10 = 0, note5 = 0, note2 = 0, note1 = 0;

  printf("Digite o valor que deseja sacar: ");
  scanf("%f", &bankWithdrawal);

  float counterWithdrawal = bankWithdrawal;

  while (counterWithdrawal != 0) {
    if (counterWithdrawal >= 100) {
      note100++;
      counterWithdrawal -= 100;

    } else if (counterWithdrawal >= 50) {
      note50++;
      counterWithdrawal -= 50;

    } else if (counterWithdrawal >= 20) {
      note20++;
      counterWithdrawal -= 20;

    } else if (counterWithdrawal >= 10) {
      note10++;
      counterWithdrawal -= 10;

    } else if (counterWithdrawal >= 5) {
      note5++;
      counterWithdrawal -= 5;

    } else if (counterWithdrawal >= 2) {
      note2++;
      counterWithdrawal -= 2;

    } else if (counterWithdrawal >= 1) {
      note1++;
      counterWithdrawal -= 1;
    }
  }

  printf("Para sacar a quantia de R$%.2f utilizando o menor número de notas possíveis: \n", bankWithdrawal);
  if (note100 != 0) {
    printf("%d notas de 100;\n", note100);
  }
  if (note50 != 0) {
    printf("%d notas de 50;\n", note50);
  }
  if (note20 != 0) {
    printf("%d notas de 20;\n", note20);
  }
  if (note10 != 0) {
    printf("%d notas de 10;\n", note10);
  }
  if (note5 != 0) {
    printf("%d notas de 5;\n", note5);
  }
  if (note2 != 0) {
    printf("%d notas de 2;\n", note2);
  }
  if (note1 != 0) {
    printf("%d notas de 1;\n", note1);
  }

  return 0;
}
