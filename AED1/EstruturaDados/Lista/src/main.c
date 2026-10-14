#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Data {
  int code;
  char name[30];
  float price;
} Data;

typedef struct Node {
  Data data;
  struct Node *pNext;
} Node;

typedef struct {
  Node *pFirst;
  size_t nodeCount;
} List;

bool reset(List **list) {
  *list = (List *)malloc(sizeof(List));
  if (*list == NULL) {
    printf("\nErro ao alocar memória!\n");
    return false;
  }

  (*list)->pFirst = NULL;
  (*list)->nodeCount = 0;

  return true;
}

bool empty(List *list) { return list->pFirst == NULL; }

bool push(List *list, Data *data, size_t position) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL) {
    printf("\nErro ao alocar memória!\n");
    return false;
  }

  newNode->data = *data;
  newNode->pNext = NULL;

  if (list->pFirst == NULL) {
    list->pFirst = newNode;
  } else {
    if (position == 0) {
      newNode->pNext = list->pFirst;
      list->pFirst = newNode;
    } else {
      Node *current = list->pFirst;
      size_t counter = 0;

      while (current != NULL && counter < position - 1) {
        current = current->pNext;
        counter++;
      }

      if (current != NULL) {
        newNode->pNext = current->pNext;
        current->pNext = newNode;
      } else {
        current = list->pFirst;
        while (current->pNext != NULL) {
          current = current->pNext;
        }

        current->pNext = newNode;
      }
    }
  }

  list->nodeCount++;
  return true;
}

bool pop(List *list, Data *data, size_t position) {
  if (empty(list)) {
    printf("\nA lista está vazia!\n");
    return false;
  }

  Node *removedNode = list->pFirst;
  Node *previousNode = NULL;

  if (position == 0) {
    list->pFirst = removedNode->pNext;
    *data = removedNode->data;
    free(removedNode);
    list->nodeCount--;
    return true;
  }

  size_t counter = 0;
  while (removedNode != NULL && counter < position) {
    previousNode = removedNode;
    removedNode = removedNode->pNext;
    counter++;
  }

  if (removedNode == NULL) {
    printf("\nPosição Inválida!\n");
    return false;
  }

  previousNode->pNext = removedNode->pNext;
  *data = removedNode->data;
  free(removedNode);
  list->nodeCount--;

  return true;
}

bool clear(List *list) {
  Node *current = list->pFirst;
  Node *auxNode;

  while (current != NULL) {
    auxNode = current;
    current = current->pNext;
    free(auxNode);
  }

  list->pFirst = NULL;
  list->nodeCount = 0;

  return true;
}

int main() {
  List *list = NULL;

  if (!reset(&list)) {
    return 1;
  }

  Data item1 = {1, "Produto A", 10.5};
  Data item2 = {2, "Produto B", 20.3};
  Data item3 = {3, "Produto C", 30.7};

  push(list, &item1, 0);
  push(list, &item2, 1);
  push(list, &item3, 2);

  printf("Nós na lista: %zu\n", list->nodeCount);

  Data removed;
  if (pop(list, &removed, 1)) {
    printf("Removido: %s\n", removed.name);
  }

  printf("Nós na lista após remoção: %zu\n", list->nodeCount);

  clear(list);
  printf("Lista limpa! Nós restantes: %zu\n", list->nodeCount);

  free(list);
  return 0;
}
