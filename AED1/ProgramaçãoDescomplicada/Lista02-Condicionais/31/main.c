#include <stdio.h>

int main() {
  float height, weight;

  printf("Digite a altura de uma pessoa (em metros): ");
  scanf("%f", &height);
  printf("Digite o peso de uma pessoa (em quilos): ");
  scanf("%f", &weight);

  if (height < 1.20) {
    if (weight < 60) {
      printf("Classificação A.\n\n");
    }
    if (weight >= 60 && weight <= 90) {
      printf("Classificação D.\n\n");
    }
    if (weight > 90) {
      printf("Classificação G.\n\n");
    }
  }

  if (height >= 1.20 && height <= 1.70) {
    if (weight < 60) {
      printf("Classificação B.\n\n");
    }
    if (weight >= 60 && weight <= 90) {
      printf("Classificação E.\n\n");
    }
    if (weight > 90) {
      printf("Classificação H.\n\n");
    }
  }

  if (height > 1.70) {
    if (weight < 60) {
      printf("Classificação C.\n\n");
    }
    if (weight >= 60 && weight <= 90) {
      printf("Classificação F.\n\n");
    }
    if (weight > 90) {
      printf("Classificação I.\n\n");
    }
  }

  return 0;
}
