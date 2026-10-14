#include <stdio.h>

int main() {
  int numberOfInhabitants, monthlyConsumption, consumerCode;
  int maxConsumption, minConsumption = __INT_MAX__, averageConsumption = 0;
  int totalConsumptionOne, totalConsumptionTwo, totalConsumptionThree;
  // float energyValue;

  printf("Digite o número de habitantes: ");
  scanf("%d", &numberOfInhabitants);
  // printf("Digite o valor da energia elétrica: ");
  // scanf("%f", &energyValue);

  for (int counter = 0; counter < numberOfInhabitants; counter++) {
    printf("Digite o consumo do mês do %dº habitante: ", counter + 1);
    scanf("%d", &monthlyConsumption);
    printf("Digite o código do consumidor (1-Residencial, 2-Comercial, 3-Industrial): ");
    scanf("%d", &consumerCode);
    printf("\n\n");

    if (maxConsumption < monthlyConsumption) {
      maxConsumption = monthlyConsumption;
    }
    if (minConsumption > monthlyConsumption) {
      minConsumption = monthlyConsumption;
    }

    averageConsumption += monthlyConsumption;

    switch (consumerCode) {
      case 1:
        totalConsumptionOne += monthlyConsumption;
        break;
      case 2:
        totalConsumptionTwo += monthlyConsumption;
        break;
      case 3:
        totalConsumptionThree += monthlyConsumption;
        break;
    }
  }

  averageConsumption /= numberOfInhabitants;

  printf("O maior consumo de energia foi: %d kwh.\n", maxConsumption);
  printf("O menor consumo de energia foi: %d kwh.\n", minConsumption);
  printf("A média de consumo dos habitantes foi: %d kwh.\n", averageConsumption);
  printf("Total de consumo residencial foi: %d kwh.\n", totalConsumptionOne);
  printf("Total de consumo comercial foi: %d kwh.\n", totalConsumptionTwo);
  printf("Total de consumo industrial foi: %d kwh.\n\n", totalConsumptionThree);

  return 0;
}