#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int number;
} Data;

typedef struct Node {
  int identifier;
  Data data;
  struct Node *pLeft;
  struct Node *pRight;
} Node;

typedef struct {
  Node *pRoot;
  size_t nodeCounter;
} minHeap;

int *convertNumberToBits(int number, size_t *size) {
  *size = (int)(log2(number)) + 1;
  int *bits = (int *)malloc(*size * sizeof(int));
  if (bits == NULL) {
    printf("\nError allocating memory!\n");
    return NULL;
  }

  for (int counter = 0; counter < *size; counter++) {
    bits[counter] = (number >> (*size - counter - 1)) & 1;
  }

  return bits;
}

Node *findParent(minHeap *heap, int identifier) {
  if (identifier == 1) return NULL;

  size_t size;
  int *idInBits = convertNumberToBits(identifier, &size);
  if (idInBits == NULL) return NULL;

  Node *parent = heap->pRoot;

  for (int counter = 1; counter < size - 1; counter++) {
    if (idInBits[counter] == 1) {
      parent = parent->pRight;
    } else {
      parent = parent->pLeft;
    }
  }

  free(idInBits);
  return parent;
}

void heapifyUp(minHeap *heap, Node *node) {
  if (node == heap->pRoot) return;

  Node *parent = findParent(heap, node->identifier);
  while (parent != NULL && node->data.number < parent->data.number) {
    Data temp = node->data;
    node->data = parent->data;
    parent->data = temp;

    node = parent;
    parent = findParent(heap, node->identifier);
  }
}

void heapifyDown(minHeap *heap, Node *node) {
  while (node->pLeft != NULL) {
    Node *smallest = node->pLeft;

    if (node->pRight != NULL && node->pRight->data.number < node->pLeft->data.number) {
      smallest = node->pRight;
    }

    if (node->data.number <= smallest->data.number) {
      break;
    }

    Data temp = node->data;
    node->data = smallest->data;
    smallest->data = temp;

    node = smallest;
  }
}

bool reset(minHeap **heap) {
  *heap = (minHeap *)malloc(sizeof(minHeap));
  if (*heap == NULL) {
    printf("\nError allocating memory!\n");
    return false;
  }

  (*heap)->pRoot = NULL;
  (*heap)->nodeCounter = 0;

  return true;
}

bool empty(minHeap *heap) { return heap->nodeCounter == 0; }

bool push(minHeap *heap, Data *data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL) {
    printf("\nError allocating memory!\n");
    return false;
  }

  newNode->identifier = heap->nodeCounter + 1;
  newNode->data = *data;
  newNode->pLeft = NULL;
  newNode->pRight = NULL;

  if (heap->nodeCounter == 0) {
    heap->pRoot = newNode;
    heap->nodeCounter++;
    return true;
  }

  Node *parent = findParent(heap, newNode->identifier);

  if (parent->pLeft == NULL) {
    parent->pLeft = newNode;
  } else {
    parent->pRight = newNode;
  }

  heapifyUp(heap, newNode);

  heap->nodeCounter++;
  return true;
}

bool pop(minHeap *heap, Data *data) {
  if (empty(heap)) {
    printf("\nError! Empty List!\n");
    return false;
  }

  *data = heap->pRoot->data;

  if (heap->nodeCounter == 1) {
    free(heap->pRoot);
    heap->pRoot = NULL;
    heap->nodeCounter = 0;
    return true;
  }

  Node *lastParent = findParent(heap, heap->nodeCounter);
  Node *lastNode;

  if (lastParent == NULL) {
    free(heap->pRoot);
    heap->pRoot = NULL;
    heap->nodeCounter = 0;
    return true;
  }

  if (lastParent->pRight != NULL) {
    lastNode = lastParent->pRight;
    lastParent->pRight = NULL;
  } else {
    lastNode = lastParent->pLeft;
    lastParent->pLeft = NULL;
  }

  heap->pRoot->data = lastNode->data;
  free(lastNode);
  heap->nodeCounter--;

  heapifyDown(heap, heap->pRoot);

  return true;
}

void clearRecursive(Node *node) {
  if (node == NULL) return;

  clearRecursive(node->pLeft);
  clearRecursive(node->pRight);
  free(node);
}

bool clear(minHeap *heap) {
  if (heap == NULL) return false;

  clearRecursive(heap->pRoot);
  heap->pRoot = NULL;
  heap->nodeCounter = 0;

  return true;
}

void printHeapRecursive(Node *node, int depth) {
  if (node == NULL) return;

  for (int i = 0; i < depth; i++) printf("  ");  // Indentação visual
  printf("%d\n", node->data.number);

  printHeapRecursive(node->pLeft, depth + 1);
  printHeapRecursive(node->pRight, depth + 1);
}

void printHeap(minHeap *heap) {
  if (empty(heap)) {
    printf("\nError! Empty Heap!\n");
    return;
  }
  printf("Heap structure:\n");
  printHeapRecursive(heap->pRoot, 0);
  printf("\n");
}

int main() {
  minHeap *heap;
  Data removedData;

  if (!reset(&heap)) {
    return 1;
  }

  Data data1 = {7};
  Data data2 = {5};
  Data data3 = {3};
  Data data4 = {4};
  Data data5 = {6};

  push(heap, &data1);
  push(heap, &data2);
  push(heap, &data3);
  push(heap, &data4);
  push(heap, &data5);

  printHeap(heap);

  pop(heap, &removedData);
  printf("Removed: %d\n", removedData.number);
  printHeap(heap);

  clear(heap);
  printHeap(heap);
  free(heap);

  return 0;
}
