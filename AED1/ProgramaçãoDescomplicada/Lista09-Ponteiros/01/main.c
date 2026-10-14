#include <stdio.h>

int main() {
  int *pointerInt, numberInt = 17;
  float *pointerFloat, numberFloat = 9.5;
  char *pointerChar, letterChar = 'G';

  printf("%d\n", numberInt);
  printf("%.1f\n", numberFloat);
  printf("%c\n\n", letterChar);

  pointerInt = &numberInt;
  pointerFloat = &numberFloat;
  pointerChar = &letterChar;

  *pointerInt = 18;
  *pointerFloat = 10.5;
  *pointerChar = 'F';

  printf("%d\n", numberInt);
  printf("%.1f\n", numberFloat);
  printf("%c\n", letterChar);

  return 0;
}