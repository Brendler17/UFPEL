#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int value;
} Data;

typedef struct Node {
  Data data;
  struct Node* pLeft;
  struct Node* pRight;
} Node;

typedef struct {
  Node* pRoot;
} Tree;

bool reset(Tree** tree) {
  *tree = (Tree*)malloc(sizeof(Tree));
  if (*tree == NULL) {
    printf("\nError allocating memory!\n");
    return false;
  }

  (*tree)->pRoot = NULL;

  return true;
}

Node* recursivePush(Node* node, Data* data) {
  if (node == NULL) {
    node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
      printf("\nError allocating memory!\n");
      return NULL;
    }

    node->data = *data;
    node->pLeft = NULL;
    node->pRight = NULL;
    return node;  // Retorna o novo nó alocado
  }

  if (data->value < node->data.value) {
    node->pLeft = recursivePush(node->pLeft, data);  // Atualiza o ponteiro do filho a esquerda
  } else if (data->value > node->data.value) {
    node->pRight = recursivePush(node->pRight, data);  // Atualiza o ponteiro do filho a direita
  } else {
    printf("\nRegister already exists!\n");
  }

  return node;  // Retorna o próprio nó, caso não tenha sido criado um novo nó
}

bool push(Tree* tree, Data* data) {
  if (tree == NULL) return false;
  tree->pRoot = recursivePush(tree->pRoot, data);  // Atualiza a raiz da árvore
  return true;
}

Node* findMax(Node* node) {
  while (node->pRight != NULL) {
    node = node->pRight;
  }

  return node;
}

Node* findMin(Node* node) {
  while (node->pLeft != NULL) {
    node = node->pLeft;
  }

  return node;
}

Node* recursivePop(Node* node, int value) {
  if (node == NULL) {
    printf("\nRegister don't exists!\n");
    return NULL;  // Se o nó não existe retorna NULL
  }

  if (value < node->data.value) {
    node->pLeft = recursivePop(node->pLeft, value);  // Busca na esquerda
  } else if (value > node->data.value) {
    node->pRight = recursivePop(node->pRight, value);  // Busca na direita
  } else {                                             // Nó encontrado

    // Caso 1 - Nó folha (sem filhos)
    if (node->pLeft == NULL && node->pRight == NULL) {
      free(node);
      return NULL;
    }

    // Caso 2 - Apenas um filho
    if (node->pLeft == NULL) {
      Node* aux = node->pRight;
      free(node);
      return aux;
    } else if (node->pRight == NULL) {
      Node* aux = node->pLeft;
      free(node);
      return aux;
    }

    // Caso 3 - Dois filhos (remover o menor a direita)
    Node* aux = findMin(node->pRight);
    node->data = aux->data;
    node->pRight = recursivePop(node->pRight, aux->data.value);
  }

  return node;
}

bool pop(Tree* tree, int value) {
  if (tree == NULL) return false;
  tree->pRoot = recursivePop(tree->pRoot, value);
  return true;
}

void clearRecursive(Node* node) {
  if (node == NULL) return;

  clearRecursive(node->pLeft);
  clearRecursive(node->pRight);
  free(node);
}

bool clear(Tree* tree) {
  if (tree == NULL) return false;

  clearRecursive(tree->pRoot);
  tree->pRoot = NULL;

  return true;
}

void printTreePreOrder(Node* node, int depth) {
  if (node == NULL) return;

  for (int i = 0; i < depth; i++) printf("  ");
  printf("%d\n", node->data.value);

  printTreePreOrder(node->pLeft, depth + 1);
  printTreePreOrder(node->pRight, depth + 1);
}

void printTreeInOrder(Node* node, int depth) {
  if (node == NULL) return;

  printTreeInOrder(node->pLeft, depth + 1);

  for (int i = 0; i < depth; i++) printf("  ");
  printf("%d\n", node->data.value);

  printTreeInOrder(node->pRight, depth + 1);
}

void printTreePosOrder(Node* node, int depth) {
  if (node == NULL) return;

  printTreePosOrder(node->pLeft, depth + 1);
  printTreePosOrder(node->pRight, depth + 1);

  for (int i = 0; i < depth; i++) printf("  ");
  printf("%d\n", node->data.value);
}

void printTree(Tree* tree) {
  if (tree == NULL) return;

  printTreeInOrder(tree->pRoot, 0);
}

int main(int argc, char const* argv[]) {
  Tree* tree;
  if (!reset(&tree)) {
    return 1;
  }

  // Inserindo elementos na árvore
  int values[] = {50, 30, 70, 20, 40, 60, 80};
  for (int i = 0; i < 7; i++) {
    Data data = {values[i]};
    push(tree, &data);
  }

  printf("\nÁrvore em pré-ordem após inserções:\n");
  printTree(tree);

  // Removendo um nó folha (20)
  printf("\nRemovendo o nó folha 20...\n");
  pop(tree, 20);
  printTree(tree);

  // Removendo um nó com um único filho (30)
  printf("\nRemovendo o nó 30 (que tem um filho)...\n");
  pop(tree, 30);
  printTree(tree);

  // Removendo um nó com dois filhos (50 - raiz)
  printf("\nRemovendo o nó raiz 50 (que tem dois filhos)...\n");
  pop(tree, 50);
  printTree(tree);

  // Limpando a árvore
  printf("\nLimpando a árvore...\n");
  clear(tree);
  printTree(tree);

  free(tree);
  return 0;
}
