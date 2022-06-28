#ifndef Q5
#define Q5

#include <stdlib.h>

typedef struct lista
{
  struct no* cabeca;
}Lista;

typedef struct no
{
  int valor;
  struct no* prox;
}No;

Lista* start() {
  Lista* l = (Lista*)malloc(sizeof(Lista));
  l->cabeca = (No*)malloc(sizeof(No));

  l->cabeca->valor = 10;
  l->cabeca->prox = (No*)malloc(sizeof(No));

  l->cabeca->prox->valor = 20;
  l->cabeca->prox->prox = (No*)malloc(sizeof(No));

  l->cabeca->prox->prox->valor = 30;
  l->cabeca->prox->prox->prox = (No*)malloc(sizeof(No));
  
  l->cabeca->prox->prox->prox->valor = 40;
  l->cabeca->prox->prox->prox->prox = NULL;

  return l;
}

#endif // !Q5.H