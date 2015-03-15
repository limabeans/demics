#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
  int *array;
  int top;
  int capacity;
} stack;

stack *create_stack(int cap) {
  stack *ref = (stack*) malloc(sizeof(stack));
  ref->array = (int*) malloc(cap * sizeof(int));
  ref->top = -1;
  ref->capacity = cap;
  return ref;
}

void delete_stack(stack *ref) {
  free(ref->array);
  free(ref);
}

void push(stack *ref, int x) {
  if(ref->top+1<ref->capacity) {
    ref->top++;
    ref->array[ref->top] = x;
  } else {
    printf("Your stack has reached max capacity.\n");
  }
}

int pop(stack *ref) {
  if(ref->top<0) {
    printf("Your stack is empty, nothing to pop.\n");
    return -99999999; //return garbage value
  } else {
    int num = ref->array[ref->top];
    ref->top--;
    return num;
  }
}

void print(stack *ref) {
  int i;
  for(i = 0; i <= ref->top; i++) {
    printf("%d ", ref->array[i]);
  }
  printf("\n");
}

int main() {
  stack *st = create_stack(5);
  int i;
  for(i=0; i<=2; i++) {
    push(st,i);
    print(st);
  }
  printf("the num popped is: %d\n", pop(st));
  print(st);
  for(i=3; i<=9; i++) {
    push(st,i);
    print(st);
  }
  delete_stack(st);
  return 0;
}
