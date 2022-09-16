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

void to_print (Nodo *n) {
  if (n == NULL) {
    return;
  }
  printf("\n%d", n->value);
  to_print(n->left);
  to_print(n->right);
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

int counting_leaf (Nodo *root){
  if (root == NULL){
    return 0;
  } else if((root->right == NULL && root->left != NULL) || (root->right != NULL && root->left == NULL)){
    return 1;
  }else{
    return counting_leaf(root->right) + counting_leaf(root->left);
  }
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
  int op, start, info, quant_leaf;

  printf("PASSO INICIAL:\nInsira um valor inteiro para a raíz: ");
  scanf("%d", &start);
  Nodo *root = create(start);

  do{
    printf("\n\n1 - Adicionar valor\n2 - Imprimir árvore\n3 - Verif. Estr. BIN\n0 - Sair\nOpção: ");
    scanf("%d", &op);
    switch(op){
      case 1:
        printf("\nInsira um valor inteiro para adicionar: ");
        scanf("%d", &info);
        add(root, info);
      break;

      case 2:
        to_print(root);
      break;

      case 3:
        quant_leaf = counting_leaf(root);
        if (quant_leaf != 0){
          printf("\nA árvore NÃO é estritamente binária");
        }else{
          printf("\nA árvore é ESTRITAMENTE BINÁRIA");
        }
        
      break;

      case 0:
        free_Tree(root);
        printf("\nSaindo ...\n");
      break;

      default:
        printf("\nERRO: Opção inválida!\n");

    }
  }while(op != 0);

  
  return 0;
}
