#include <stdio.h>

int main() {
  int a, *b, **c, ***d;

  printf("Digite um valor: ");
  scanf("%d", &a);

  b = &a;
  c = &b;
  d = &c;

  printf("O valor é: %d\n", a);
  printf("O dobro do valor é: %d\n", *b * 2);
  printf("O triplo do valor é: %d\n", **c * 3);
  printf("O quádruplo do valor é: %d\n", ***d * 4);

  return 0;
}
