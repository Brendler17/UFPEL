#include <stdio.h>

static int currentYear = 2024;

int main() {
  int day, month, year;

  printf("Digite uma data de anivesário (separada por / ): ");
  scanf("%d/%d/%d", &day, &month, &year);

  if ((day > 0 && day <= 31) && year <= currentYear) {
    if (day <= 30 && (month == 4 || month == 6 || month == 9 || month == 11)) {
      printf("A data de aniverário %d/%d/%d é válida!\n\n", day, month, year);
      return 0;
    }

    if (day <= 31 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)) {
      printf("A data de aniverário %d/%d/%d é válida!\n\n", day, month, year);
      return 0;
    }

    if (day <= 29 && month == 2) {
      if (day <= 28) {
        printf("A data de aniverário %d/%d/%d é válida!\n\n", day, month, year);
        return 0;
      }

      if (day == 29 && ((year % 4) == 0 && (year % 100) != 0)) {
        printf("A data de aniverário %d/%d/%d é válida!\n\n", day, month, year);
        return 0;
      }
    }
  }

  printf("A data de aniverário %d/%d/%d é inválida!\n\n", day, month, year);
  return 1;
}
