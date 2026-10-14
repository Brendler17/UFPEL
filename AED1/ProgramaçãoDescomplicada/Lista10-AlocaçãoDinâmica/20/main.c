#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EARTH_RADIUS 6371.0
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

typedef struct {
  double latitude, longitude;
} Coords;

typedef struct {
  char name[15];
  Coords position;
} City;

double degreesToRadians(double degrees) { return degrees * M_PI / 180.0; }

double getDistanceWithHaversine(City cityOne, City cityTwo) {
  double latOne = degreesToRadians(cityOne.position.latitude);
  double lonOne = degreesToRadians(cityOne.position.longitude);
  double latTwo = degreesToRadians(cityTwo.position.latitude);
  double lonTwo = degreesToRadians(cityTwo.position.longitude);

  double latDiff = latTwo - latOne;
  double lonDiff = lonTwo - lonOne;

  double a = sin(latDiff / 2) * sin(latDiff / 2) + cos(latOne) * cos(latTwo) * sin(lonDiff / 2) * sin(lonDiff / 2);
  double c = 2 * atan2(sqrt(a), sqrt(1 - a));

  return EARTH_RADIUS * c;
}

void removeTrailingNewLine(char* string) {
  size_t len = strlen(string);
  if (len > 0 && string[len - 1] == '\n') {
    string[len - 1] = '\0';
  }
}

void freeMatrix(double** matrix, size_t numberOfLines) {
  if (matrix != NULL) {
    for (size_t line = 0; line < numberOfLines; line++) {
      free(matrix[line]);
    }

    free(matrix);
  }
}

int main() {
  City* cities;
  double** distanceMatrix = NULL;
  size_t numberOfCities, cityOne, cityTwo;

  printf("Digite o número de cidades a serem cadastradas: ");
  if (scanf("%zu", &numberOfCities) != 1 || numberOfCities <= 0) {
    printf("\nValor inválido!\n");
    return 1;
  }

  cities = (City*)malloc(numberOfCities * sizeof(City));
  if (cities == NULL) {
    printf("\nErro ao alocar memória!\n");
    return 1;
  }

  for (size_t city = 0; city < numberOfCities; city++) {
    printf("\nDigite as informações da %zuª cidade\n", city + 1);
    printf("Nome: ");
    getchar();
    fgets(cities[city].name, 15, stdin);
    removeTrailingNewLine(cities[city].name);
    printf("\nCoordenadas\n");
    printf("Latitude: ");
    scanf("%lf", &cities[city].position.latitude);
    printf("Longitude: ");
    scanf("%lf", &cities[city].position.longitude);
  }

  distanceMatrix = (double**)malloc(numberOfCities * sizeof(double*));
  if (distanceMatrix == NULL) {
    printf("\nErro ao alocar memória!\n");
    return 1;
  }

  for (size_t line = 0; line < numberOfCities; line++) {
    distanceMatrix[line] = (double*)malloc(numberOfCities * sizeof(double));
    if (distanceMatrix[line] == NULL) {
      printf("\nErro ao alocar memória!\n");
      freeMatrix(distanceMatrix, line);
      return 1;
    }
  }

  for (size_t line = 0; line < numberOfCities; line++) {
    for (size_t column = 0; column < numberOfCities; column++) {
      if (line == column) {
        distanceMatrix[line][column] = 0.0;
      } else {
        distanceMatrix[line][column] = getDistanceWithHaversine(cities[line], cities[column]);
      }
    }
  }

  printf("\nMatriz de distâncias\n\n");
  printf("%-15s", "");
  for (size_t counter = 0; counter < numberOfCities; counter++) {
    printf("%-15s", cities[counter].name);
  }
  printf("\n");
  for (size_t line = 0; line < numberOfCities; line++) {
    printf("%-15s", cities[line].name);
    for (size_t column = 0; column < numberOfCities; column++) {
      printf("%-15.2f", distanceMatrix[line][column]);
    }
    printf("\n");
  }

  while (1) {
    printf("\nDigite os números das duas cidades para calcular sua distância (1 a %zu): ", numberOfCities);
    if (scanf("%zu %zu", &cityOne, &cityTwo) != 2 || (cityOne <= 0 && cityOne > numberOfCities) ||
        (cityTwo <= 0 && cityTwo > numberOfCities)) {
      printf("\nValores inválidos!\n");
      return 1;
    }

    printf("\nA distância entre %s e %s é de %.2f km.\n\n", cities[cityOne - 1].name, cities[cityTwo - 1].name,
           distanceMatrix[cityOne - 1][cityTwo - 1]);
  }

  freeMatrix(distanceMatrix, numberOfCities);
  free(cities);

  return 0;
}