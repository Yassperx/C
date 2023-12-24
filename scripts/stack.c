#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int number;
  struct node *next;
} node;

typedef struct stack {
  node *top;
} stack;

void init_stack(stack *s) {
  s->top = NULL;
}

void on_stack(stack *s, int number) {
  if (s == NULL) {
    return;
  }
  node *tmp = malloc(sizeof(node));
  tmp->number = number;
  tmp->next = s->top;
  s->top = tmp;
}

int pop_stack(stack *s) {
  if (s == NULL || s->top == NULL) {
    return 0;
  }
  node *n = s->top;
  s->top = s->top->next;
  return n->number;
  free(n);
}

void print_stack(stack *s) {
  node *n = s->top;
  while (n != NULL) {
    printf("%i\n", n->number);
    n = n->next;
  }
}

void free_stack(stack *s) {
  while (s->top != NULL) {
    node *n = s->top;
    s->top = s->top->next;
    free(n);
  }
}

int main(void) {
  stack monstack;
  init_stack(&monstack);

  int list[] = {1, 3, 2, 5, 4, 9, 7};

  for (int i = 0; i < sizeof(list) / sizeof(list[0]); i++) {
    on_stack(&monstack, list[i]);
  }

  print_stack(&monstack);
  
  for (int i = 0; i < 3; i ++)
  {
    pop_stack(&monstack);
  }
  printf("Removing 3 first elements...\n");

  print_stack(&monstack);

  free_stack(&monstack);

  return 0;
}
