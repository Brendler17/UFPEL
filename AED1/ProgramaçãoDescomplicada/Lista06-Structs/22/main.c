#include <stdio.h>
#include <string.h>

struct Adress {
  char road[15], neighborhood[15], city[15], state[15];
  int CEP;
};

struct Register {
  char name[10], matiralStatus[10], sex[10];
  int identity, phone, CPF, age;
  float wage;
  struct Adress adress;
};

void showMenu() {
  printf("\n---------- MENU -----------\n");
  printf("1 - Preencher cadastro;\n");
  printf("2 - Encontrar pessoa mais velha;\n");
  printf("3 - Encontrar pessoas do sexo masculino;\n");
  printf("4 - Encontrar pessoas com sálario maior que R$1.000;\n");
  printf("5 - Imprimir dados da pessoa que possua um número específico de identificação;\n");
  printf("0 - Sair\n\n");
}

void fillRegister(struct Register *p) {
  printf("Digite o nome: ");
  getchar();
  scanf(" %[^\n]", p->name);
  printf("Digite o número de identidade: ");
  scanf("%d", &p->identity);
  printf("Digite o CPF: ");
  scanf("%d", &p->CPF);
  printf("Digite o sexo: ");
  scanf("%s", p->sex);
  printf("Digite o estado civil: ");
  scanf("%s", p->matiralStatus);
  printf("Digite a idade: ");
  scanf("%d", &p->age);
  printf("Digite o salário: ");
  scanf("%f", &p->wage);
  printf("Digite o telefone: ");
  scanf("%d", &p->phone);
  printf("---------- Endereço -----------\n");
  printf("Digite a cidade: ");
  getchar();
  scanf(" %[^\n]", p->adress.city);
  printf("Digite o estado: ");
  getchar();
  scanf(" %[^\n]", p->adress.state);
  printf("Digite a rua: ");
  getchar();
  scanf(" %[^\n]", p->adress.road);
  printf("Digite o bairro: ");
  getchar();
  scanf(" %[^\n]", p->adress.neighborhood);
  printf("Digite o CEP: ");
  scanf("%d", &p->adress.CEP);
}

struct Register findOlderPerson(struct Register peoples[], int length) {
  struct Register olderPeople = peoples[0];

  for (int counter = 1; counter < length; counter++) {
    if (peoples[counter].age > olderPeople.age) {
      olderPeople = peoples[counter];
    }
  }

  return olderPeople;
}

void findMalePerson(struct Register peoples[], int length) {
  printf("---------- Pessoas do Sexo Masculino -----------\n");
  for (int counter = 0; counter < length; counter++) {
    if (strcmp(peoples[counter].sex, "Masculino") == 0) {
      printf("Nome: %s.\n", peoples[counter].name);
    }
  }
}

void findWagePerson(struct Register peoples[], int length) {
  printf("---------- Pessoas com Salário Maior que R$1.000,00 -----------\n");
  for (int counter = 0; counter < length; counter++) {
    if (peoples[counter].wage >= 1000.00) {
      printf("Nome: %s.\n", peoples[counter].name);
    }
  }
}

struct Register findPersonIdentity(struct Register peoples[], int length, int identity) {
  struct Register identifiedPerson;

  for (int counter = 0; counter < length; counter++) {
    if (peoples[counter].identity == identity) {
      identifiedPerson = peoples[counter];
    }
  }

  return identifiedPerson;
}

int main() {
  struct Register peoples[5];
  struct Register olderPerson;
  struct Register identifiedPerson;
  int option;

  showMenu();
  printf("Digite sua escolha: ");
  scanf("%d", &option);

  while (option != 0) {
    switch (option) {
      case 1:
        for (int counter = 0; counter < 5; counter++) {
          printf("\n---------- Cadastro %d -----------\n", counter + 1);
          fillRegister(&peoples[counter]);
        }
        break;

      case 2:
        olderPerson = findOlderPerson(peoples, 5);
        printf("\n---------- Pessoa Mais Velha -----------\n");
        printf("Nome: %s.\n", olderPerson.name);
        printf("Idade: %d.\n\n", olderPerson.age);
        break;

      case 3:
        findMalePerson(peoples, 5);
        break;

      case 4:
        findWagePerson(peoples, 5);
        break;

      case 5:
        int identity;
        printf("Digite o número de identidade que deseja consultar: ");
        scanf("%d", &identity);
        identifiedPerson = findPersonIdentity(peoples, 5, identity);
        printf("\n---------- Pessoa identificada -----------\n");
        printf("Nome: %s.\n\n", olderPerson.name);
        if (identifiedPerson.name[0] == '\0') {
          printf("Pessoa não identificada!\n\n");
        }

        memset(&identifiedPerson, 0, sizeof(identifiedPerson));
        break;

      default:
        printf("Digite uma opção válida!\n\n");
        break;
    }

    showMenu();
    printf("\nDigite sua escolha: ");
    scanf("%d", &option);
  }

  return 0;
}