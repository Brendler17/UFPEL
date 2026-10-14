#include <stdbool.h>
#include <stdio.h>

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
  int flowersPlaced = n;

  for (int counter = 0; counter < flowerbedSize; counter++) {
    if (counter == 0 && *flowerbed == 0) {
      int* flowerBefore = flowerbed + 1;
      flowersPlaced--;
      *flowerbed = 1;
    }

    else if ((flowerbedSize == (counter + 1)) && *flowerbed == 0) {
      int* flowerAfter = flowerbed - 1;
      if (*flowerAfter == 0) {
        flowersPlaced--;
        *flowerbed = 1;
      }
    }

    else if (*flowerbed == 0) {
      int* flowerAfter = flowerbed - 1;
      int* flowerBefore = flowerbed + 1;
      if (*flowerAfter == 0 && *flowerBefore == 0) {
        flowersPlaced--;
        *flowerbed = 1;
      }
    }

    flowerbed++;
  }

  if (flowersPlaced == 0) {
    return true;
  } else {
    return false;
  }
}

int main() {
  int flowerBed[5] = {0, 0, 1, 0, 0};
  int flowerBedSize = sizeof(flowerBed) / sizeof(flowerBed[0]);
  int n = 1;

  bool result = canPlaceFlowers(&flowerBed[0], flowerBedSize, n);
  printf(result ? "True" : "False");

  return 0;
}
