#include <stdio.h>

int main() {
  int day, month, year;

  printf("Digite uma data (separada por /): ");
  scanf("%d/%d/%d", &day, &month, &year);

  if ((day >= 1 && day <= 31) && (month >= 1 && month <= 12)) {
    if ((month == 4 || month == 6 || month == 9 || month == 11) && (day <= 30)) {
      printf("A data %d/%d/%d é válida!\n\n", day, month, year);
      return 0;
    }

    if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && (day <= 31)) {
      printf("A data %d/%d/%d é válida!\n\n", day, month, year);
      return 0;
    }

    if (month == 2) {
      if (day <= 28) {
        printf("A data %d/%d/%d é válida!\n\n", day, month, year);
        return 0;
      }
      if ((day == 29) && (year % 4 == 0)) {
        printf("A data %d/%d/%d é válida!\n\n", day, month, year);
        return 0;
      }
    }
  }

  printf("Data Inválida!\n\n");
  return 1;
}
