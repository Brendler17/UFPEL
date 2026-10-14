#include <math.h>
#include <stdio.h>

int main() {
  float stepHeight;
  int numberOfStepsClimbed, numberOfSteps;

  printf("Digite a altura do degrau de uma escada (em metros): ");
  scanf("%f", &stepHeight);
  printf("Digite a altura que deseja alcançar subindo a escada (em metros): ");
  scanf("%d", &numberOfStepsClimbed);
  numberOfSteps = ceil((float)numberOfStepsClimbed / stepHeight);
  printf("Deverá subir %d degraus para atingir a marca.\n\n", numberOfSteps);

  return 0;
}