#include <stdio.h>

int main() {
  int input, seconds, minutes, hours;

  printf("Digite um valor em segundos: ");
  scanf("%d", &input);

  hours = input / 3600;
  minutes = (input / 60) % 60;
  seconds = input % 60;

  printf("%d horas, ", hours);
  printf("%d minutos, ", minutes);
  printf("%d segundos.\n\n", seconds);

  return 0;
}
