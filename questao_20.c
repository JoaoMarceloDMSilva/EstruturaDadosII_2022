#include <stdio.h>
#include <stdlib.h>

struct nodo {
  int value;
  struct nodo *left;
  struct nodo *right;
};

typedef struct  nodo Nodo;

Nodo* create(int num){
  Nodo *no = malloc(sizeof(Nodo));
  no -> value = num;
  no -> left = NULL;
  no -> right = NULL;
  return no;
}

void add (Nodo *n, int num) {
  if (num == n->value){
    return;
  }

  if (num < n->value){

    if (n->left == NULL){
      n->left = create(num);
    }
    else {
      add(n->left, num);
    }

  }else{

    if (n -> right == NULL){
      n->right = create(num);
    }
    else {
      add(n->right, num);
    }
  }
}

void to_print_EmOrdem (Nodo *n) {
  if (n == NULL) {
    return;
  }
  to_print_EmOrdem(n->left);
  printf("\n%d", n->value);
  to_print_EmOrdem(n->right);
}

void to_print_PosOrdem (Nodo *n) {
  if (n == NULL) {
    return;
  }
  to_print_PosOrdem(n->left);
  to_print_PosOrdem(n->right);
  printf("\n%d", n->value);
}

void to_print_PreOrdem (Nodo *n) {
  if (n == NULL) {
    return;
  }
  printf("\n%d", n->value);
  to_print_PreOrdem(n->left);
  to_print_PreOrdem(n->right);
}

Nodo* free_Tree (Nodo *root){
  if (root == NULL){
    return 0;
  }
  free_Tree(root->left);
  free_Tree(root->right);
  free(root);
  root = NULL;
}


int main () {
  Nodo *root = create(33);

  add(root,15);
  add(root,41);
  add(root,47);
  add(root,38);
  add(root,34);
  add(root,43);
  add(root,49);

  printf("\nEm Pré-Ordem:\n");
  to_print_PreOrdem(root);
  printf("\n\t- - - - - - - - - - - -\n");

  printf("\nEm Em-Ordem:\n");
  to_print_EmOrdem(root);
  printf("\n\t- - - - - - - - - - - -\n");

  printf("\nEm Pós-Ordem:\n");
  to_print_PosOrdem(root);

  free_Tree(root);
  return 0;
}
