#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char* elements;
  int top;
  int capacity;
} Stack;

bool reset(Stack* stack, int capacity) {
  stack->elements = (char*)malloc(capacity * sizeof(char));
  if (stack->elements == NULL) {
    printf("\nError allocating memory!\n");
    return false;
  }

  stack->top = -1;
  stack->capacity = capacity;
  return true;
}

bool empty(Stack* stack) { return stack->top == -1; }

bool push(Stack* stack, char bracket) {
  stack->top++;
  stack->elements[stack->top] = bracket;

  return true;
}

bool pop(Stack* stack, char* bracket) {
  if (empty(stack)) {
    printf("Error! Empty stack.\n");
    return false;
  }

  *bracket = stack->elements[stack->top];
  stack->top--;

  return true;
}

bool clear(Stack* stack) {
  if (stack->elements) {
    free(stack->elements);
    stack->elements = NULL;
  }

  stack->top = -1;
  stack->capacity = 0;

  return true;
}

bool isValid(char* string) {
  size_t len = strlen(string);

  if (len % 2 != 0) return false;

  Stack stack;
  if (!(reset(&stack, len))) return false;

  char bracket;

  for (int counter = 0; counter < len; counter++) {
    char c = string[counter];

    if (c == '(' || c == '[' || c == '{') {
      push(&stack, c);
    } else {
      if (!pop(&stack, &bracket)) {
        clear(&stack);
        return false;
      }

      if ((c == ')' && bracket != '(') || (c == ']' && bracket != '[') || (c == '}' && bracket != '{')) {
        clear(&stack);
        return false;
      }
    }
  }

  bool valid = empty(&stack);

  clear(&stack);
  return valid;
}

int main() {
  char* testCases[] = {"()", "()[]{}", "(]", "([])", "(("};
  for (int counter = 0; counter < 5; counter++) {
    isValid(testCases[counter]) ? printf("True\n") : printf("False\n");
  }
  return 0;
}
