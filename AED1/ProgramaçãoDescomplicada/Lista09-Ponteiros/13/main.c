#include <stdbool.h>
#include <stdio.h>

bool checkStrings(char* stringOne, char* stringTwo) {
  char *currentOne, *currentTwo, *startOne;

  for (currentOne = stringOne; *currentOne != '\0'; currentOne++) {
    if (*currentOne == *stringTwo) {
      startOne = currentOne;
      currentTwo = stringTwo;

      while (*currentOne == *currentTwo && *currentTwo != '\0') {
        currentOne++;
        currentTwo++;
      }

      if (*currentTwo == '\0') {
        return true;
      }

      currentOne = startOne;
    }
  }
  return false;
}

int main() {
  char stringOne[25] = {"Aritimética de Ponteiros"}, stringTwo[20] = {"ica de Pont"};

  bool occours = checkStrings(&stringOne[0], &stringTwo[0]);
  occours ? printf("A segunda string ocorre dentro da primeira.\n\n")
          : printf("A segunda string não ocorre dentro da primeira.\n\n");

  return 0;
}
