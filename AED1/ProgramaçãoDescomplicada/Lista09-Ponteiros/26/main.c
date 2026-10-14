#include <math.h>
#include <stdio.h>

int roots(float a, float b, float c, float* x1, float* x2, float* delta) {
  *delta = pow(b, 2) - 4 * a * c;

  if (*delta < 0) {
    return 0;
  } else if (*delta == 0) {
    *x1 = (-b + sqrt(*delta)) / 2 * a;
    *x2 = (-b - sqrt(*delta)) / 2 * a;
    return 1;
  } else if (*delta > 0) {
    *x1 = (-b + sqrt(*delta)) / 2 * a;
    *x2 = (-b - sqrt(*delta)) / 2 * a;
    return 2;
  }

  return 0;
}

int main() {
  float a, b, c;
  float x1, x2;
  float delta;
  int numberOfRoots;

  printf("Digite os coeficiente da equação de segundo grau\n");
  printf("Coeficiente quadrático (x²): ");
  scanf("%f", &a);
  printf("Coeficiente linear (x): ");
  scanf("%f", &b);
  printf("Coeficiente constante: ");
  scanf("%f", &c);

  numberOfRoots = roots(a, b, c, &x1, &x2, &delta);

  printf("\nA equação possui %d raiz(es)", numberOfRoots);
  delta == 0 ? printf(": %.2f", x1) : delta > 0 ? printf(": %.2f e %.2f", x1, x2) : printf(".");
  printf("\n\n");

  return 0;
}