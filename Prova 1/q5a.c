#include <stdio.h>
#include "q5.h"

void concatenar(Lista* l1, Lista* l2);

int main() {

  Lista* l1 = start();
  Lista* l2 = start();

  concatenar(l1,l2);
  for (No* aux = l1->cabeca; aux != NULL; aux = aux->prox) { printf("%d | ", aux->valor); }
  return 0;
}

void concatenar(Lista* l1, Lista* l2) {

  if (l1 == NULL) {
    l1 = l2;
  }

  No* aux;
  for (aux = l1->cabeca; aux->prox != NULL; aux = aux->prox) {}
  aux->prox = l2->cabeca;

  free(l2);

}