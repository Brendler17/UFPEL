#include <stdio.h>

int main() {
  int code, quantity;

  printf("Digite o código do produto: ");
  scanf("%d", &code);
  printf("Digite a quantidade do produto escolhido: ");
  scanf("%d", &quantity);

  switch (code) {
    case 100:
      printf("Produto escolhido: Cachorro Quente | Total: R$%.2f\n\n", quantity * 1.20);
      break;
    case 101:
      printf("Produto escolhido: Bauru Simples | Total: R$%.2f\n\n", quantity * 1.30);
      break;
    case 102:
      printf("Produto escolhido: Bauru c/ Ovo | Total: R$%.2f\n\n", quantity * 1.50);
      break;
    case 103:
      printf("Produto escolhido: Hámburguer | Total: R$%.2f\n\n", quantity * 1.20);
      break;
    case 104:
      printf("Produto escolhido: Cheeseburguer | Total: R$%.2f\n\n", quantity * 1.70);
      break;
    case 105:
      printf("Produto escolhido: Suco | Total: R$%.2f\n\n", quantity * 2.20);
      break;
    case 106:
      printf("Produto escolhido: Refrigerante | Total: R$%.2f\n\n", quantity * 1.00);
      break;
    default:
      printf("Produto não encontrado!\n\n");
      return 1;
      break;
  }

  return 0;
}
