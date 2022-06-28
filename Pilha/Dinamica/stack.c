#include "stack.h"

struct no {
  No* ant;
  int valor;
}No;

struct pilha {

  No* topo;

}Pilha;

Pilha* criarPilha(){
  return (Pilha*) malloc(sizeof(Pilha));
}

No* criarNo(int valor){
  No* novo = (No*) malloc(sizeof(No));
  novo->valor = valor;
  return novo;
}

int empilhar(Pilha* p, No* n){
  
}

int desempilhar(Pilha* p, No* n){
  
}

No* obterTopo(Pilha* p){
  return p->topo;
}
 // Ambas as funções desempenham papeis parecidos
void mostrarTopo(Pilha* p){
  
}

int estaVazia(Pilha* p){
  
}

// int estaCheia(); // função implementada normalmente em estruturas estaticas