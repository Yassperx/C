#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int number;
  struct node *next;
} node;

int main(void) {
  // List of size 0
  node *list = NULL;
  
  // List to link
  int normal_list[] = {1, 2, 4, 5, 3, 9, 7, 8};
  int size = sizeof(normal_list) / sizeof(normal_list[0]);

  for (int i = 0; i < size; i++) {
    node *n = malloc(sizeof(node));
    if (n == NULL) {
      return 1;
    }

    n->number = normal_list[i];
    n->next = list;
    list = n;
  }

  // Print the list
  for (node *tmp = list; tmp != NULL; tmp = tmp->next) {
    printf("%i\n", tmp->number);
  }

  // Free the allocated memory
  while (list != NULL) {
    node *temp = list;
    list = list->next;
    free(temp);
  }

  return 0;
}
