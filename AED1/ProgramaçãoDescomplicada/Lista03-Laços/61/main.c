#include <stdio.h>

int isPalindrome(int number) {
  int reversed = 0, original = number;

  while (number > 0) {
    reversed = reversed * 10 + (number % 10);
    number /= 10;
  }

  return reversed == original;
}

int main() {
  int numberOne, numberTwo, maxPalindrome = 0;

  for (int counterOne = 999; counterOne >= 100; counterOne--) {
    for (int counterTwo = 999; counterTwo >= 100; counterTwo--) {
      int result = counterOne * counterTwo;
      if (result > maxPalindrome && isPalindrome(result)) {
        maxPalindrome = result;
        numberOne = counterTwo;
        numberTwo = counterOne;
      }
    }
  }

  printf("O maior palíndrono resultante do produto de dois números de três dígitos é: ");
  printf("%d, que é o produto de %d e %d.\n\n", maxPalindrome, numberOne, numberTwo);
  return 0;
}
