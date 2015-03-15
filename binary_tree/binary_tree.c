//A binary tree if integers that supports all basic operations.
#include <stdlib.h>
#include <stdio.h>
#include "binary_tree.h"

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

void add(binary_tree *tree, int d) {
  if(tree->head==NULL) {
    tree->head = create_node(d);
  } else {
    node *walker = tree->head;
    //Keep looping until you find a place to add.
    while(1) {
      if(d < walker->data) {
	if(walker->left == NULL) {
	  walker->left = create_node(d);
	  break;
	} else {
	  walker = walker->left;
	}
      } else { //d >= walker->data
	if(walker->right == NULL) {
	  walker->right = create_node(d);
	  break;
	} else {
	  walker = walker->right;
	}
      }
    }
  }
}

int search(binary_tree *tree, int x) {
  if(tree!=NULL) {
    node *walker = tree->head;
    while(walker!=NULL) {
      if(walker->data == x) {
	return 1;
      } else if (x < walker->data) {
	walker = walker->left;
      } else {
	walker = walker->right;
      }
    }
    return 0;
  }
  return 0;
}

int main() {
  binary_tree *tree = create_tree(3);
  add(tree, 2);
  add(tree, 1);
  add(tree, 4);
  add(tree,-1);
  printf("%d\n", search(tree, 6));
  printf("%d\n", search(tree, 4));
  print_inorder(tree);
  delete_binary_tree(tree);

  return 0;
}
