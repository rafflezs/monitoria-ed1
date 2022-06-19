#include <stdio.h>
#include "q6.h"

void removerFim(No* n, Desc* d);

int main() {

  No* n = (No*) malloc(sizeof(No)); 
  Desc* d = (Desc*) malloc(sizeof(Desc));
  start(n,d);

  No* aux;
  for (aux = n; aux != NULL; aux = aux->prox) { printf("%d | ", aux->dado); }
  removerFim(n,d);
  printf("\n");
  for (aux = n; aux != NULL; aux = aux->prox) { printf("%d | ", aux->dado); }

  return 0;
}

void removerFim(No* n, Desc* d) {

  if (n == NULL) {
    return;
  }

  if (d->fim == NULL) {
    return;
  }

  No* aux = d->fim;
  aux = aux->ant;
  aux->prox = NULL;
  d->qtd--;
  d->fim = aux;

}