#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

typedef struct node {
  int data;
  struct node *left;
  struct node *right;
} node;

typedef struct binary_tree {
  struct node *head;
} binary_tree;

node *create_node(int);
void print_node(node*);
void delete_node(node*);
binary_tree *create_tree(int);
void print_inorder(binary_tree*);
void print_inorder_helper(node*);
void delete_binary_tree(binary_tree*);
void add(binary_tree*, int);

#endif 
