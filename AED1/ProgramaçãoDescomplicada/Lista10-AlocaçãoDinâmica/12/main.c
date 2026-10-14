#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[50];
  int identificationCode, quantityAvaliable;
  float salePrice;
} Product;

void removeTrailingNewLine(char* string) {
  size_t len = strlen(string);
  if (len > 0 && string[len - 1] == '\n') {
    string[len - 1] = '\0';
  }
}

Product getHighestSellingPrice(Product* buffer, size_t numberOfProducts) {
  Product productHighestPrice = buffer[0];

  for (int counter = 1; counter < numberOfProducts; counter++) {
    if (buffer[counter].salePrice > productHighestPrice.salePrice) {
      productHighestPrice = buffer[counter];
    }
  }

  return productHighestPrice;
}

Product getLargestQuantityAvaliable(Product* buffer, size_t numberOfProducts) {
  Product productLargestQuantityAvaliable = buffer[0];

  for (int counter = 1; counter < numberOfProducts; counter++) {
    if (buffer[counter].quantityAvaliable > productLargestQuantityAvaliable.quantityAvaliable) {
      productLargestQuantityAvaliable = buffer[counter];
    }
  }

  return productLargestQuantityAvaliable;
}

int main() {
  Product *buffer, productHighestPrice, productLargestQuantityAvaliable;
  size_t numberOfProducts;

  printf("Digite a quantidade de produtos a serem cadastrados: ");
  scanf("%zu", &numberOfProducts);

  buffer = (Product*)malloc(numberOfProducts * sizeof(Product));
  if (buffer == NULL) {
    printf("Erro ao alocar memória!\n");
    return 1;
  }

  for (int counter = 0; counter < numberOfProducts; counter++) {
    getchar();
    printf("\nDigite as informações do %dº produto:\n", counter + 1);

    printf("Nome: ");
    fgets(buffer[counter].name, sizeof(buffer[counter].name), stdin);
    removeTrailingNewLine(buffer[counter].name);

    printf("Código de identificação: ");
    scanf("%d", &buffer[counter].identificationCode);

    printf("Quantidade disponível: ");
    scanf("%d", &buffer[counter].quantityAvaliable);
    printf("Preço de venda: R$");

    scanf("%f", &buffer[counter].salePrice);
    printf("\n");
  }

  productHighestPrice = getHighestSellingPrice(buffer, numberOfProducts);
  productLargestQuantityAvaliable = getLargestQuantityAvaliable(buffer, numberOfProducts);

  printf("\nO produto com o maior preço de venda é:\n");
  printf("Nome: %s\n", productHighestPrice.name);
  printf("Código: %d\n", productHighestPrice.identificationCode);
  printf("Preço: R$%.2f\n", productHighestPrice.salePrice);

  printf("\nO produto com a maior quantidade disponível no estoque é:\n");
  printf("Nome: %s\n", productLargestQuantityAvaliable.name);
  printf("Código: %d\n", productLargestQuantityAvaliable.identificationCode);
  printf("Quantidade: %d\n", productLargestQuantityAvaliable.quantityAvaliable);

  printf("\n\n");

  free(buffer);

  return 0;
}