#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
  int dado;
  struct no* prox;
  struct no* ant;
}No;


void popular(No** cabeca) ;

int main () {

  No* lista = NULL;
  popular(&lista);

  // Trecho para inserir o no A
  No* A = (No*) malloc(sizeof(No));
  A->dado = 7;

  No* aux = lista;
  
  // Assumindo que os valores da lista são apenas os informados no exercicio
  while (aux->dado != 5)  {aux = aux->prox;}

  A->prox = aux->prox;
  A->ant = aux;
  aux->prox = A;

  for (No* iterator = lista; iterator != NULL; iterator = iterator->prox) {
    if (iterator->ant != NULL) {
      printf("ANT: %d | ", iterator->ant->dado);
    }    
    printf("%d | ", iterator->dado);
    if (iterator->prox != NULL) {
      printf("PROX: %d | ", iterator->prox->dado);
    }
    printf("\n");
  }

}

void popular(No** cabeca) {

  // inicializa a lista e popula
  No* novo = (No*)malloc(sizeof(No));
  novo->ant = NULL;
  novo->dado = 3;

  No* prox1 = malloc(sizeof(No));
  prox1->ant = novo;
  prox1->dado = 1;

  No* prox2 = malloc(sizeof(No));
  prox2->ant = prox1;
  prox2->dado = 5;

  No* prox3 = malloc(sizeof(No));
  prox3->ant = prox2;
  prox3->prox = NULL;
  prox3->dado = 8;

  novo->prox = prox1;
  prox1->prox = prox2;
  prox2->prox = prox3;
  *cabeca = novo;
}