//A binary tree if integers that supports all basic operations.
#include <stdlib.h>
#include <stdio.h>

//structs.
typedef struct node {
  int data;
  struct node *left;
  struct node *right;
} node;

typedef struct binary_tree {
  struct node *head;
} binary_tree;

//headers.
node *create_node(int);
void delete_node(node*);
binary_tree *create_tree(int);
void delete_binary_tree(binary_tree*);

//implementation.
node *create_node(int data) {
  node *head = (node*)malloc(sizeof(node));
  head->data = data;
  return head;
}

void delete_node(node *head) {
  free(head);
}


binary_tree *create_tree(int head_data) {
  binary_tree *tree = (binary_tree*)malloc(sizeof(binary_tree));
  tree->head = create_node(head_data);
  return tree;
}

void delete_binary_tree(binary_tree *tree) {
  delete_node(tree->head);
  free(tree);
}


int main() {
  binary_tree *tree = create_tree(3);
  delete_binary_tree(tree);

  return 0;
}
