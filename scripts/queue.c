#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int number;
  struct node* next;
} node;

typedef struct queue {
  node* head;
  node* tail;
} queue;

void init_queue(queue* q) {
  q->head = NULL;
  q->tail = NULL;
}

void enqueue(queue* q, int value) {
  node* n = malloc(sizeof(node)); 
  n->number = value;
  n->next = NULL;
  if (q->tail != NULL) {
    q->tail->next = n;
  }
  q->tail = n;
  if (q->head == NULL) {
    q->head = n;
  }
}

void dequeue(queue* q) {
  if (q->head == NULL) {
    return;
  }
  node* tmp = q->head;
  q->head = q->head->next;

  if (q->head == NULL) {
    q->tail = NULL;
  }

  free(tmp);
}

int main(void) {
  queue t;
  init_queue(&t); 
  enqueue(&t, 10);
  enqueue(&t, 20);
  enqueue(&t, 30);

  for (node* tmp = t.head; tmp != NULL; tmp = tmp->next) {
    printf("%i\n", tmp->number);
  }

  dequeue(&t);
  dequeue(&t);

  printf("After Dequeue:\n");

  for (node* tmp = t.head; tmp != NULL; tmp = tmp->next) {
    printf("%i\n", tmp->number);
  }

  return 0;
}
