// implementation of stack in c
// methods needed
// push
// pop
// view
// display
//

#include <stdbool.h>
#include <stdio.h>
#define N 5
typedef struct {
  int top;
  int stack[N];
} Stack;

bool isempty(Stack *s) {
  if (s->top == -1) {
    return true;
  }
  return false;
}

void push(Stack *s, int num) {
  if (s->top == N - 1) {
    printf("Stack Overflow\n");
  } else {
    ++(s->top);
    s->stack[s->top] = num;
  }
}

int pop(Stack *s) {
  if (isempty(s)) {
    printf("The stack is empty\n");
  }
  return (s->stack[s->top--]);
}
int peek(Stack *s) {
  if (isempty(s)) {
    printf("The stack is empty\n");
  }
  return (s->stack[s->top]);
}
size_t empty(Stack *s) {
  if (isempty(s)) {
    printf("The stack is empty\n");
    return -1;
  }
  s->top = -1;
  return 0;
}
void print_stack(const Stack *s) {
  for (int i = s->top; i >= 0; --i) {
    if (s->stack[i] == 0)
      continue;
    printf("%d\n", s->stack[i]);
  }
}
int main() {
  Stack s;
  s.top = -1;
  push(&s, 1);
  push(&s, 3);
  print_stack(&s);
  pop(&s);
  print_stack(&s);
  empty(&s);
  printf("After applying empty\n");
  print_stack(&s);
  push(&s, 3);
  printf("Seeking: %d\n", peek(&s));
  return 0;
}
