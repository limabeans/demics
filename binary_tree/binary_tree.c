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
void print_node(node*);
void delete_node(node*);
binary_tree *create_tree(int);
void print_inorder(binary_tree*);
void print_inorder_helper(node*);
void delete_binary_tree(binary_tree*);

//implementation.
node *create_node(int data) {
  node *head = (node*)malloc(sizeof(node));
  head->data = data;
  head->left = NULL;
  head->right = NULL;
  return head;
}
void print_node(node *head) {
  printf("%d ", head->data);
}
void delete_node(node *head) {
  if(head!=NULL) {
    delete_node(head->left);
    delete_node(head->right);
    free(head);
  }
}
binary_tree *create_tree(int head_data) {
  binary_tree *tree = (binary_tree*)malloc(sizeof(binary_tree));
  tree->head = create_node(head_data);
  return tree;
}
void print_inorder(binary_tree *tree) {
  if(tree!=NULL) {
    print_inorder_helper(tree->head);
  }
  printf("\n");
}
void print_inorder_helper(node *curr) {
  if(curr!=NULL) {
    print_inorder_helper(curr->left);

    printf("%d ", curr->data);
    print_inorder_helper(curr->right);
  }
}
void delete_binary_tree(binary_tree *tree) {
  delete_node(tree->head);
  free(tree);
}

int main() {
  binary_tree *tree = create_tree(3);
  tree->head->left = create_node(2);
  tree->head->right = create_node(4);
  print_inorder(tree);
  delete_binary_tree(tree);

  return 0;
}
