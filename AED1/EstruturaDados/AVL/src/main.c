#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  size_t identifier;
} Data;

typedef struct Node {
  Data data;
  struct Node *pLeft;
  struct Node *pRight;
} Node;

typedef struct {
  Node *pRoot;
  size_t nodeCounter;
} Tree;

int getHeight(Node *node) {
  if (node == NULL) return 0;

  int counterLeft = getHeight(node->pLeft);
  int counterRight = getHeight(node->pRight);

  return (counterLeft > counterRight ? counterLeft : counterRight) + 1;
}

int getBalancingFactor(Node *node) {
  if (node == NULL) return 0;

  return getHeight(node->pLeft) - getHeight(node->pRight);
}

int isAvl(Node *node) {
  int balancingFactor;

  if (node == NULL) return 1;  // Uma árvore vazia é AVL por definição

  if (!(isAvl(node->pLeft))) {  // Se a subárvore esquerda não for AVL, a árvore não é AVL
    return 0;
  }
  if (!(isAvl(node->pRight))) {  // Se a subárvore direita não for AVL, a árvore não é AVL
    return 0;
  }

  // Se o fator de balanceamento não estiver entre -1 e 1, a árvore não é AVL
  balancingFactor = getBalancingFactor(node);
  if ((balancingFactor > 1) || (balancingFactor < -1)) {
    return 0;
  } else {
    return 1;  // Se todas as condições forem atendidas, a árvore é AVL
  }
}

bool reset(Tree **tree) {
  *tree = (Tree *)malloc(sizeof(Tree));
  if (*tree == NULL) {
    printf("\nError allocating memory!\n");
    return false;
  }

  (*tree)->pRoot = NULL;
  (*tree)->nodeCounter = 0;

  return true;
}

Node *simpleLeftRotation(Node *pivot) {
  if (pivot == NULL || pivot->pRight == NULL) return pivot;

  Node *aux = pivot->pRight;
  pivot->pRight = aux->pLeft;
  aux->pLeft = pivot;

  return aux;
}

Node *simpleRightRotation(Node *pivot) {
  if (pivot == NULL || pivot->pLeft == NULL) return pivot;

  Node *aux = pivot->pLeft;
  pivot->pLeft = aux->pRight;
  aux->pRight = pivot;

  return aux;
}

Node *balanced(Node *node) {
  if (node == NULL) return NULL;

  int balancingFactor = getBalancingFactor(node);

  if (balancingFactor > 1) {
    if (getBalancingFactor(node->pLeft) < 0) {
      node->pLeft = simpleLeftRotation(node->pLeft);
    }
    return simpleRightRotation(node);
  } else if (balancingFactor < -1) {
    if (getBalancingFactor(node->pRight) > 0) {
      node->pRight = simpleRightRotation(node->pRight);
    }
    return simpleLeftRotation(node);
  }

  return node;
}

Node *pushRecursive(Node *node, Data *data) {
  if (node == NULL) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
      printf("\nError allocating memory!\n");
      return NULL;
    }

    newNode->data = *data;
    newNode->pLeft = NULL;
    newNode->pRight = NULL;

    return newNode;
  }

  if (data->identifier < node->data.identifier) {
    node->pLeft = pushRecursive(node->pLeft, data);
  } else {
    node->pRight = pushRecursive(node->pRight, data);
  }

  return balanced(node);
}

bool push(Tree *tree, Data *data) {
  Node *newRoot = pushRecursive(tree->pRoot, data);
  if (newRoot == NULL) return false;

  tree->pRoot = newRoot;
  tree->nodeCounter++;

  return true;
}

Node *findMin(Node *node) {
  while (node->pLeft != NULL) {
    node = node->pLeft;
  }

  return node;
}

Node *popRecursive(Node *node, int value) {
  if (node == NULL) return node;

  if (value < node->data.identifier) {
    node->pLeft = popRecursive(node->pLeft, value);
  } else if (value > node->data.identifier) {
    node->pRight = popRecursive(node->pRight, value);
  } else {
    if (node->pLeft == NULL && node->pRight == NULL) {
      free(node);
      return NULL;
    }

    if (node->pLeft == NULL) {
      Node *aux = node->pRight;
      free(node);
      return balanced(aux);
    } else if (node->pRight == NULL) {
      Node *aux = node->pLeft;
      free(node);
      return balanced(aux);
    }

    Node *aux = findMin(node->pRight);
    node->data = aux->data;
    node->pRight = popRecursive(node->pRight, aux->data.identifier);
  }

  return balanced(node);
}

bool pop(Tree *tree, int value) {
  if (tree == NULL) return false;

  Node *newRoot = popRecursive(tree->pRoot, value);
  if (newRoot == NULL) return false;

  tree->pRoot = newRoot;
  tree->nodeCounter--;

  return true;
}

void clearRecursive(Node *node) {
  if (node == NULL) return;

  clearRecursive(node->pLeft);
  clearRecursive(node->pRight);
  free(node);
}

bool clear(Tree *tree) {
  if (tree == NULL) return false;

  clearRecursive(tree->pRoot);
  return true;
}

void treePreOrder(Node *node, int depth) {
  if (node == NULL) return;

  for (int i = 0; i < depth; i++) printf("  ");
  printf("%zu\n", node->data.identifier);

  treePreOrder(node->pLeft, depth + 1);
  treePreOrder(node->pRight, depth + 1);
}

void treePosOrder(Node *node, int depth) {
  if (node == NULL) return;

  treePosOrder(node->pLeft, depth + 1);
  treePosOrder(node->pRight, depth + 1);

  for (int i = 0; i < depth; i++) printf("  ");
  printf("%zu\n", node->data.identifier);
}

void treeInOrder(Node *node, int depth) {
  if (node == NULL) return;

  treeInOrder(node->pLeft, depth + 1);

  for (int i = 0; i < depth; i++) printf("  ");
  printf("%zu\n", node->data.identifier);

  treeInOrder(node->pRight, depth + 1);
}

void printTree(Tree *tree) {
  if (tree == NULL) return;

  treePreOrder(tree->pRoot, 0);
}

int main() {
  int number;

  Tree *tree;
  if (!(reset(&tree))) {
    return 1;
  }

  do {
    printf("Enter a number: ");
    scanf("%d", &number);

    if (number == 0) {
      break;
    }

    Data data = {number};

    push(tree, &data);

    printTree(tree);

  } while (number != 0);

  clear(tree);
  free(tree);

  return 0;
}
