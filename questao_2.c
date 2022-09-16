#include <stdio.h>
#include <stdlib.h>

struct nodo {
  int value;
  struct no *left;
  struct no *right;
};

typedef struct nodo Nodo;

Nodo* create (int num){
  Nodo *no = malloc(sizeof(Nodo));
  no -> value = num;
  no -> left = NULL;
  no -> right = NULL;
  return no;
}

void add (Nodo *n, int num){
  if (num == n -> value){
    return;
  }
  if (num < n -> value){
    if(n -> left == NULL){
      n->left = create(num);
    } else {
      add(n -> left, num);
    }
  }else {
    if (n -> right == NULL){
      n -> right = create(num);
    } else {
      add(n->right, num);
    }
  }
}

void toPrint(Nodo *n){
  if (n == NULL){
    toPrint(n->left);
    toPrint(n->right);
  }
}

Nodo* free_Tree (Nodo *root){
  if (root == NULL){
    return;
  }
  free_Tree(root->left);
  free_Tree(root->right);
  free(root);
  root = NULL;
}

int countingNodes(Nodo *root){
  if ( root == NULL){
    return 0;
  }else {
    return 1 + countingNodes(root->right) + countingNodes(root->left);
  }
}

int main(void) {
  int op, start, info, altura, quant_Nos;
  printf("\nInserir o nó da raiz: ");
  scanf("%d", &start);
  Nodo *raiz = create(start);
  do{
    printf("\n - - - - - - - - - ");
    printf("\n1 -> Adicionar um valor\n2 -> Quantidade de nós\n0 -> SAIR");
    printf("\n - - - - - - - - -\n ");
    scanf("%d", &op);

    switch (op){
      case 1:
      printf("\nInserir valor: ");
      scanf("%d", &info);
      add(raiz,info);
      break;

      case 2:
      quant_Nos = countingNodes(raiz);
      printf("\nQuant. de Nós: %d\n", quant_Nos);
      break;

      case 0:
      free_Tree(root);
      printf("\nSAINDO ...");
      break;

      default:
      printf("\nOpção inválida!");
    }
  } while(op != 0);

  return 0;
}
