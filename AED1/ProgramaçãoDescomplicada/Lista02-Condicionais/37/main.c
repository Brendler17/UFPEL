#include <stdio.h>

int main() {
  int incomingHour, incomingMinute, incomingTotal, exitHour, exitMinute, exitTotal, totalHours;
  float valueTotal = 0.0;

  printf("Indique a hora de chegada (horas:minutos): ");
  scanf("%d:%d", &incomingHour, &incomingMinute);
  if (incomingHour > 24 && incomingMinute > 60) {
    printf("Hora inválida!\n\n");
    return 1;
  }

  printf("Indique a hora de saída (horas:minutos): ");
  scanf("%d:%d", &exitHour, &exitMinute);
  if (exitHour > 24 && exitMinute > 60) {
    printf("Hora inválida!\n\n");
    return 1;
  }

  incomingTotal = (incomingHour * 60) + incomingMinute;
  exitTotal = (exitHour * 60) + exitMinute;

  if (incomingTotal > exitTotal) {
    exitTotal += 24 * 60;
  }

  totalHours = (exitTotal - incomingTotal + 59) / 60;

  if (totalHours <= 2) {
    valueTotal = totalHours * 1.0;
  }

  else if (totalHours <= 4) {
    valueTotal = (totalHours - 2) * 1.40 + (2 * 1.0);
  }

  else {
    valueTotal = (totalHours - 4) * 2.0 + (2 * 1.40) + (2 * 1.0);
  }

  printf("O valor que deverá ser cobrado pelo estacionamento é R$%.2f\n\n", valueTotal);

  return 0;
}
