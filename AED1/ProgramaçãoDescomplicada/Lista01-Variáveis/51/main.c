#include <math.h>
#include <stdio.h>

int main() {
  int x1, y1, root, result;

  printf("Digite as coordenadas de um ponto (separadas por espaço): ");
  scanf("%d %d", &x1, &y1);

  root = pow(x1, 2) + pow(y1, 2);
  result = sqrt(root);

  printf("A distância do ponto P(%d,%d) até a origem é %d.\n\n", x1, y1, result);

  return 0;
}
