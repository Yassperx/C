#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
  int number;
  struct node *left;
  struct node *right;
} node ;

void free_tree(node *root);
void print_tree(node *root);

int main(void)
{
  //Tree of size 0
  node *tree = NULL;
  node *n = malloc(sizeof(node));
  if (n == NULL)
  {
    return 1;
  }
  n->number=2;
  n->left=NULL;
  n->right=NULL;
  tree = n;

  //Add another number to list
  n = malloc(sizeof(node));
  if (n == NULL)
  {
    return 1;
  }
  n->number = 1;
  n->right=NULL;
  n->left=NULL;
  tree->left=n;

  //Add again another number to list
  n = malloc(sizeof(node));
 
  if (n == NULL)
  {
    return 1;
  }
  
  n->number=3;
  n->right=NULL;
  n->left=NULL;
  tree->right = n;
  
  print_tree(tree);
  free_tree(tree);

  return 0;
}

void free_tree(node *root)
{
  if (root == NULL)
  {
    return;
  }
  free_tree(root->left);
  free_tree(root->right);
  free(root);
}

void print_tree(node *root)
{
  if (root == NULL)
  {
    return;
  }

  print_tree(root->left);
  printf("%i\n", root->number);
  print_tree(root->right);
}

bool search(node *tree, int number)
{
  if (tree == NULL)
  {
    return false;
  } else if (number > tree->number) {
    search(tree->right, number);
  } else if (number < tree->number) {
    search(tree->right, number);
  } else {
    return true;
  }
  return false;
}
