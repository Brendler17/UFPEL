#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

void inOrder(struct TreeNode *node, struct TreeNode **first, struct TreeNode **second, struct TreeNode **prev) {
  if (node == NULL) return;

  inOrder(node->left, first, second, prev);

  if (*prev && (*prev)->val > node->val) {
    if (*first == NULL) {
      *first = *prev;
    }

    *second = node;
  }

  *prev = node;
  inOrder(node->right, first, second, prev);
}

void recoverTree(struct TreeNode *root) {
  struct TreeNode *prev = NULL, *first = NULL, *second = NULL;

  inOrder(root, &first, &second, &prev);

  if (first != NULL && second != NULL) {
    int aux = first->val;
    first->val = second->val;
    second->val = aux;
  }
}

int main() { return 0; }