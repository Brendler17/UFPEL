#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum { RED, BLACK } Color;

typedef struct {
  size_t identifier;
} Data;

typedef struct Node {
  Data data;
  Color color;
  struct Node *pLeft;
  struct Node *pRight;
  struct Node *pParent;
} Node;

typedef struct {
  Node *pRoot;
  Node *pNil;
} Tree;

void pushCase1(Tree *tree, Node *node);

Node *getGrandParent(Node *node) {
  if (node != NULL && node->pParent != NULL) {
    return node->pParent->pParent;
  }

  return NULL;
}

Node *getUncle(Node *node) {
  Node *grandParent = getGrandParent(node);
  if (grandParent == NULL) return NULL;

  if (node->pParent == grandParent->pLeft) {
    return grandParent->pRight;
  } else {
    return grandParent->pLeft;
  }
}

Node *simpleLeftRotation(Tree *tree, Node *pivot) {
  if (pivot == NULL || pivot->pRight == tree->pNil) return pivot;

  Node *aux = pivot->pRight;
  pivot->pRight = aux->pLeft;
  if (aux->pLeft != tree->pNil) {
    aux->pLeft->pParent = pivot;
  }

  aux->pParent = pivot->pParent;

  if (pivot->pParent == tree->pNil) {
    tree->pRoot = aux;
  } else if (pivot == pivot->pParent->pLeft) {
    pivot->pParent->pLeft = aux;
  } else {
    pivot->pParent->pRight = aux;
  }

  aux->pLeft = pivot;
  pivot->pParent = aux;

  return aux;
}

Node *simpleRightRotation(Tree *tree, Node *pivot) {
  if (pivot == NULL || pivot->pLeft == tree->pNil) return pivot;

  Node *aux = pivot->pLeft;
  pivot->pLeft = aux->pRight;
  if (aux->pRight != tree->pNil) {
    aux->pRight->pParent = pivot;
  }

  aux->pParent = pivot->pParent;

  if (pivot->pParent == tree->pNil) {
    tree->pRoot = aux;
  } else if (pivot == pivot->pParent->pLeft) {
    pivot->pParent->pLeft = aux;
  } else {
    pivot->pParent->pRight = aux;
  }

  aux->pRight = pivot;
  pivot->pParent = aux;

  return aux;
}

void pushCase5(Tree *tree, Node *node) {
  Node *grandParent = getGrandParent(node);

  if ((node == node->pParent->pLeft) && (node->pParent == grandParent->pLeft)) {
    simpleRightRotation(tree, grandParent);
  } else {
    simpleLeftRotation(tree, grandParent);
  }

  node->pParent->color = BLACK;
  grandParent->color = RED;
}

void pushCase4(Tree *tree, Node *node) {
  Node *grandParent = getGrandParent(node);

  if ((node == node->pParent->pRight) && (node->pParent == grandParent->pLeft)) {
    node = simpleLeftRotation(tree, node->pParent);
  } else if ((node == node->pParent->pLeft) && (node->pParent == grandParent->pRight)) {
    node = simpleRightRotation(tree, node->pParent);
  }

  pushCase5(tree, node);
}

void pushCase3(Tree *tree, Node *node) {
  Node *uncle = getUncle(node);

  if (uncle != NULL && uncle->color == RED) {  // 1ª Correção -> Se o tio do elemento inserido é VERMELHO.
    Node *grandParent = getGrandParent(node);

    node->pParent->color = BLACK;
    uncle->color = BLACK;
    grandParent->color = RED;
    if (grandParent != tree->pNil) {
      pushCase1(tree, grandParent);
    }
  } else {
    pushCase4(tree, node);
  }
}

void pushCase2(Tree *tree, Node *node) {
  if (node->pParent->color == BLACK) {  // Se tiver nó pai preto, não precisa de correção. Novo nó = VERMELHO.
    return;
  } else {
    pushCase3(tree, node);  // Se tiver o nó pai vermelho, precisará de correção - ambos filhos de todos nós vermelhos são PRETOS.
  }
}

void pushCase1(Tree *tree, Node *node) {
  if (node->pParent == tree->pNil) {  // Se não tiver nó pai, significa que ele será o nó pai = PRETO.
    node->color = BLACK;
  } else {  // Se não for o nó pai, passa para o segundo caso.
    pushCase2(tree, node);
  }
}

bool *push(Tree *tree, Data *data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL) {
    printf("\nError allocating memory!\n");
    return false;
  }

  newNode->data = *data;
  newNode->color = RED;
  newNode->pLeft = tree->pNil;
  newNode->pRight = tree->pNil;

  Node *parent = tree->pNil;
  Node *current = tree->pRoot;

  while (current != tree->pNil) {
    parent = current;

    if (data->identifier < current->data.identifier) {
      current = current->pLeft;
    } else {
      current = current->pRight;
    }
  }

  newNode->pParent = parent;

  if (parent == tree->pNil) {
    tree->pRoot = newNode;
  } else if (data->identifier < parent->data.identifier) {
    parent->pLeft = newNode;
  } else {
    parent->pRight = newNode;
  }

  pushCase1(tree, newNode);

  return true;
}

bool reset(Tree **tree) {
  *tree = (Tree *)malloc(sizeof(Tree));
  if (*tree == NULL) {
    printf("\nError allocating memory!\n");
    return false;
  }

  (*tree)->pNil = (Node *)malloc(sizeof(Node));
  if ((*tree)->pNil == NULL) {
    printf("\nError allocating memory!\n");
    free(*tree);
    return false;
  }

  (*tree)->pNil->color = BLACK;
  (*tree)->pNil->pLeft = (*tree)->pNil;
  (*tree)->pNil->pRight = (*tree)->pNil;
  (*tree)->pNil->pParent = (*tree)->pNil;

  (*tree)->pRoot = (*tree)->pNil;

  return true;
}

int main() { return 0; }
