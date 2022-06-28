#ifndef _STACK_H
#define _STACK_H

#include <stdlib.h>

typedef struct no No;
typedef struct pilha Pilha;

Pilha* criarPilha();
No* criarNo(int valor);

int empilhar(Pilha* p, No* n);
int desempilhar(Pilha* p, No* n);

No* obterTopo(Pilha* p); // Ambas as funções desempenham papeis parecidos
void mostrarTopo(Pilha* p);

int estaVazia(Pilha* p);
// int estaCheia(); // função implementada normalmente em estruturas estaticas

#endif // !_STACK_H