#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int* stack;
  int top;
  int capacity;
} SeatManager;

void push(SeatManager* obj, int seatNumber) {
  if (obj->top < obj->capacity - 1) {
    obj->top++;
    obj->stack[obj->top] = seatNumber;
  }
}

int pop(SeatManager* obj) {
  if (obj->top == -1) {
    return -1;
  }

  return obj->stack[(obj->top)--];
}

SeatManager* seatManagerCreate(int n) {
  SeatManager* stackManager = (SeatManager*)malloc(sizeof(SeatManager));
  stackManager->stack = (int*)malloc(n * sizeof(int));
  stackManager->top = -1;
  stackManager->capacity = n;

  for (int counter = n; counter >= 1; counter--) {
    push(stackManager, counter);
  }
  return stackManager;
}

int seatManagerReserve(SeatManager* obj) { return pop(obj); }

void seatManagerUnreserve(SeatManager* obj, int seatNumber) { push(obj, seatNumber); }

void seatManagerFree(SeatManager* obj) {
  free(obj->stack);
  free(obj);
}

int main() {
  SeatManager* manager = seatManagerCreate(5);

  // ✓
  // printf("Reserve: %d\n", seatManagerReserve(manager));
  // printf("Reserve: %d\n", seatManagerReserve(manager));
  // seatManagerUnreserve(manager, 1);
  // printf("Reserve: %d\n", seatManagerReserve(manager));
  //

  // X
  printf("Reserve: %d\n", seatManagerReserve(manager));
  printf("Reserve: %d\n", seatManagerReserve(manager));
  seatManagerUnreserve(manager, 1);
  seatManagerUnreserve(manager, 2);
  printf("Reserve: %d\n", seatManagerReserve(manager));
  //

  seatManagerFree(manager);
  return 0;
}
