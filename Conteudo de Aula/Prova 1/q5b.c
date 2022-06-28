#include <stdio.h>
#include "q5.h"

void procurarValor(Lista* l1, int valor);

int main() {

  Lista* l1 = start();
  for (No* aux = l1->cabeca; aux != NULL; aux = aux->prox) { printf("%d | ", aux->valor); }
  procurarValor(l1, 10);
  procurarValor(l1, 25);
  l1 = NULL;
  procurarValor(l1, 10);
  return 0;
}

void procurarValor(Lista* l1, int valor) {

  if (l1 == NULL) {
    printf("\nLista vazia!\n");
  }

  int i = 0;
  for (No* aux = l1->cabeca; aux->prox != NULL; aux = aux->prox) {
    if (aux->valor == valor) {
      printf("\nO valor %d foi encontrado na posicao %d\n", valor, i);
      return;
    }
    i++;
  }

  printf("\nO valor %d nao foi encontrado\n", valor);

}