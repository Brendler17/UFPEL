#include <stdio.h>

int main() {
  int duration, startSeconds, startMinutes, startHours, totalTime, endSeconds, endMinutes, endHours;

  printf("Digite o horário de inicio do evento (horas, minutos e segundos, separados por espaço): ");
  scanf("%d %d %d", &startHours, &startMinutes, &startSeconds);
  printf("Digite a duração do evento (segundos): ");
  scanf("%d", &duration);

  totalTime = (startHours * 3600) + (startMinutes * 60) + startSeconds + duration;

  endHours = totalTime / 3600;
  endMinutes = (totalTime / 60) % 60;
  endSeconds = totalTime % 60;

  printf("O horário de término do evento é as %d horas, %d minutos e %d segundos.\n\n", endHours, endMinutes, endSeconds);

  return 0;
}
