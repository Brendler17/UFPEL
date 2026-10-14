#include <stdio.h>

void getNotes(float* noteOne, float* noteTwo) {
  printf("Digite a primeira nota: ");
  scanf("%f", noteOne);
  printf("Digite a segunda nota: ");
  scanf("%f", noteTwo);
}

void getAverages(float noteOne, float noteTwo, float* average, float* weightedAverage) {
  *average = (noteOne + noteTwo) / 2.0;
  *weightedAverage = (noteOne + noteTwo * 2.0) / 3.0;
}

int main() {
  float noteOne, noteTwo;
  float average, weightedAverage;

  getNotes(&noteOne, &noteTwo);
  getAverages(noteOne, noteTwo, &average, &weightedAverage);

  printf("\nA média aritmética é: %.2f\n", average);
  printf("A média ponderada é: %.2f\n\n", weightedAverage);

  return 0;
}