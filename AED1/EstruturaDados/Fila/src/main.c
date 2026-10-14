#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int number;
} Data;

typedef struct Node {
  Data data;
  struct Node *pNext;
} Node;

typedef struct {
  Node *pFirst;
  Node *pLast;
  size_t size;
} Queue;

bool reset(Queue **queue) {
  *queue = (Queue *)malloc(sizeof(Queue));
  if (*queue == NULL) {
    printf("\nErro ao alocar memória!\n");
    return false;
  }

  (*queue)->pFirst = NULL;
  (*queue)->pLast = NULL;
  (*queue)->size = 0;

  return true;
}

bool empty(Queue *queue) { return queue->size == 0; }

bool push(Queue *queue, Data *data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL) {
    printf("\nErro ao alocar memória!\n");
    return false;
  }

  newNode->data = *data;
  newNode->pNext = NULL;

  if (queue->size == 0) {
    queue->pFirst = newNode;
    queue->pLast = newNode;
  } else {
    queue->pLast->pNext = newNode;
    queue->pLast = newNode;
  }

  queue->size++;

  return true;
}

bool pop(Queue *queue, Data *data) {
  if (empty(queue)) {
    printf("\nEmpty Queue!\n");
    return false;
  }

  Node *removedNode = queue->pFirst;
  *data = removedNode->data;
  queue->pFirst = removedNode->pNext;

  if (queue->pFirst == NULL) {
    queue->pLast = NULL;
  }

  free(removedNode);
  queue->size--;

  return true;
}

bool clear(Queue *queue) {
  Node *currentNode = queue->pFirst;

  while (currentNode != NULL) {
    Node *auxNode = currentNode;
    currentNode = currentNode->pNext;
    free(auxNode);
  }

  queue->pFirst = NULL;
  queue->pLast = NULL;
  queue->size = 0;

  return true;
}

int main(int argc, char const *argv[]) {
  Queue *queue = NULL;

  if (!reset(&queue)) {
    return 1;
  }

  Data item1 = {1};
  Data item2 = {2};
  Data item3 = {3};
  Data item4 = {3};
  Data item5 = {3};

  push(queue, &item1);
  push(queue, &item2);
  push(queue, &item3);
  printf("Nós na lista: %zu\n", queue->size);

  Data removed;
  if (pop(queue, &removed)) {
    printf("Removido: %d\n", removed.number);
  }
  printf("Nós na lista após remoção: %zu\n", queue->size);

  push(queue, &item4);
  push(queue, &item5);
  printf("Nós na lista: %zu\n", queue->size);

  if (pop(queue, &removed)) {
    printf("Removido: %d\n", removed.number);
  }
  printf("Nós na lista após remoção: %zu\n", queue->size);

  clear(queue);
  printf("Lista limpa! Nós restantes: %zu\n", queue->size);

  free(queue);
  return 0;
}
