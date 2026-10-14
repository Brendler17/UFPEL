#include <stdio.h>

int main() {
  float prizeValue, firstBet, secondBet, thirdBet, totalBet, firstPrize, secondPrize, thirdPrize;

  printf("Digite o valor total do prêmio: ");
  scanf("%f", &prizeValue);
  printf("Digite o valor que o primeiro amigo apostou: ");
  scanf("%f", &firstBet);
  printf("Digite o valor que o segundo amigo apostou: ");
  scanf("%f", &secondBet);
  printf("Digite o valor que o terceiro amigo apostou: ");
  scanf("%f", &thirdBet);

  totalBet = firstBet + secondBet + thirdBet;

  firstPrize = firstBet / totalBet;
  secondPrize = secondBet / totalBet;
  thirdPrize = thirdBet / totalBet;

  printf("O prêmio ganho com base no valor investido do primeiro amigo é R$%.2f\n", prizeValue * firstPrize);
  printf("O prêmio ganho com base no valor investido do segundo amigo é R$%.2f\n", prizeValue * secondPrize);
  printf("O prêmio ganho com base no valor investido do terceiro amigo é R$%.2f\n\n", prizeValue * thirdPrize);

  return 0;
}
