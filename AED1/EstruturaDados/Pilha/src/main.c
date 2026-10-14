#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[30];
  int age;
} Element;

typedef struct {
  Element *elements;
  Element *top;
  Element *base;
  int limit;
} Stack;

void removeTrailingNewLine(char *string) {
  size_t len = strlen(string);
  if (len > 0 && string[len - 1] == '\n') {
    string[len - 1] = '\0';
  }
}

void showMenu() {
  printf("\n-------------------- MENU --------------------\n");
  printf("0 - Adicionar Pessoa (Nome, Idade)\n");
  printf("1 - Remover Pessoa\n");
  printf("2 - Remover Pessoa por Nome\n");
  printf("3 - Limpar Todos\n");
  printf("4 - Listar Pessoas\n");
  printf("5 - Sair\n");
  printf("----------------------------------------------\n");
}

bool reset(Stack **stack) {
  *stack = (Stack *)malloc(sizeof(Stack));
  if (*stack == NULL) {
    printf("\nErro ao alocar memória!\n");
    return false;
  }

  (*stack)->elements = NULL;
  (*stack)->top = NULL;
  (*stack)->base = NULL;
  (*stack)->limit = 0;

  return true;
}

bool empty(Stack *stack) { return stack->top == NULL; }

bool push(Stack *stack, Element *element) {
  stack->elements = (Element *)realloc(stack->elements, (stack->limit + 1) * sizeof(Element));
  if (stack->elements == NULL) {
    printf("\nErro ao alocar memória!\n");
    return false;
  }

  stack->elements[stack->limit] = *element;
  stack->limit++;
  stack->top = &stack->elements[stack->limit - 1];
  stack->base = stack->elements;

  return true;
}

bool pop(Stack *stack, Element *element) {
  if (empty(stack)) {
    return false;
  }

  *element = stack->elements[stack->limit - 1];

  stack->limit--;

  if (stack->limit == 0) {
    free(stack->elements);
    stack->elements = NULL;
    stack->top = NULL;
    stack->base = NULL;
    stack->limit = 0;
    return true;
  }

  stack->elements = (Element *)realloc(stack->elements, stack->limit * sizeof(Element));
  if (stack->elements == NULL) {
    printf("\nErro ao alocar memória!\n");
    return false;
  }

  stack->top = &stack->elements[stack->limit - 1];
  stack->base = stack->elements;

  return true;
}

bool clear(Stack *stack) {
  if (stack->elements) {
    free(stack->elements);
    stack->elements = NULL;
  }

  stack->top = NULL;
  stack->base = NULL;
  stack->limit = 0;

  return true;
}

int main() {
  Stack *stack = NULL;
  int userOption;
  char removedName[30];

  if (!(reset(&stack))) {
    return 1;
  }

  do {
    showMenu();
    printf("Digite uma opção: ");
    scanf("%d", &userOption);

    switch (userOption) {
      case 0: {
        Element element;

        system("clear");
        printf("Digite o nome: ");
        getchar();
        fgets(element.name, 30 * sizeof(char), stdin);
        removeTrailingNewLine(element.name);
        printf("Digite a idade: ");
        scanf("%d", &element.age);

        system("clear");
        if (!(push(stack, &element))) {
          printf("\nErro ao inserir elemento!\n");
          clear(stack);
          free(stack);
          return 1;
        } else {
          printf("\nElemento inserido com sucesso!\n");
        }

        break;
      }
      case 1: {
        Element element;

        system("clear");
        if (pop(stack, &element)) {
          printf("\nElemento removido\n");
          printf("Nome: %s\n", element.name);
          printf("Idade: %d\n", element.age);
        } else {
          printf("\nErro ao remover elemento!\n");
        }

        break;
      }
      case 2: {
        Stack *auxStack = NULL;
        Element element;
        bool found = false;

        if (!(reset(&auxStack))) {
          return 1;
        }

        system("clear");
        if (!(empty(stack))) {
          printf("Digite o nome para remover: ");
          getchar();
          fgets(removedName, 30 * sizeof(char), stdin);
          removeTrailingNewLine(removedName);

          while (!(empty(stack))) {
            pop(stack, &element);

            if (strcmp(element.name, removedName) == 0) {
              found = true;
              break;
            }

            push(auxStack, &element);
          }

          system("clear");
          if (found) {
            printf("\nRegistro removido com sucesso!\n");
          } else {
            printf("\nNome não encontrado!\n");
          }

          while (!(empty(auxStack))) {
            pop(auxStack, &element);
            push(stack, &element);
          }

        } else {
          printf("\nRegistro Vazio!\n");
        }

        clear(auxStack);
        free(auxStack);
        auxStack = NULL;

        break;
      }
      case 3: {
        system("clear");
        if (!(empty(stack))) {
          clear(stack);
          printf("\nTodos registros foram apagados!\n");
        } else {
          printf("\nRegistro Vazio!\n");
        }

        break;
      }
      case 4: {
        Stack *auxStack = NULL;
        Element element;

        if (!(reset(&auxStack))) {
          return 1;
        }

        system("clear");
        if (!(empty(stack))) {
          printf("\n------------------ LISTAR ------------------\n");
          while (!(empty(stack))) {
            pop(stack, &element);

            printf("Nome: %s\n", element.name);
            printf("Idade: %d\n", element.age);
            printf("----------------------------------------------\n");

            push(auxStack, &element);
          }
          printf("\n\n");

          while (!(empty(auxStack))) {
            pop(auxStack, &element);
            push(stack, &element);
          }

        } else {
          printf("\nRegistro Vazio!\n");
        }

        clear(auxStack);
        free(auxStack);
        auxStack = NULL;

        break;
      }
      case 5: {
        printf("\nSaindo...\n");
        clear(stack);
        free(stack);
        stack = NULL;
        break;
      }

      default:
        system("clear");
        printf("\nDigite uma opção válida!\n");
        break;
    }
  } while (userOption != 5);

  return 0;
}
