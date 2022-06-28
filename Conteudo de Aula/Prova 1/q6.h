#ifndef Q6_H
#define Q6_H

#include <stdlib.h>

typedef struct no
{
  struct no *prox, *ant;
  int dado;
} No;

typedef struct desc
{
  int qtd;
  No *ini, *fim, *maior;
} Desc;

void start(No *n, Desc *d)
{
  d->qtd = 0;

  n->dado = 10;
  d->maior = n;
  d->ini = n;
  d->qtd++;
  d->fim = n;
  n->prox = (No *)malloc(sizeof(No));
  n->ant = NULL;

  n->prox->dado = 20;
  if (n->dado > d->maior->dado)
  {
    d->maior = n;
  }
  d->qtd++;
  d->fim = n->prox;
  n->prox->prox = (No *)malloc(sizeof(No));
  n->prox->ant = n;

  n->prox->prox->dado = 30;
  if (n->dado > d->maior->dado)
  {
    d->maior = n;
  }
  d->qtd++;
  d->fim = n->prox->prox;
  n->prox->prox->prox = (No *)malloc(sizeof(No));
  n->prox->prox->ant = n->prox;

  n->prox->prox->prox->dado = 40;
  if (n->dado > d->maior->dado)
  {
    d->maior = n;
  }
  d->qtd++;
  d->fim = n->prox->prox->prox;
  n->prox->prox->prox->prox = NULL;
  n->prox->prox->prox->ant = n->prox->prox;
  
}

#endif // !Q6#de