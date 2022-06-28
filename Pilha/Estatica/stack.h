#ifndef _STACK_H
#define _STACK_H

typedef struct Pilha pilha;

void criarPilha(Pilha *p, int c );

void empilhar (Pilha *p, float v);
float desempilhar (Pilha *p );

int estaCheia (Pilha *p );
int estaVazia (Pilha *p );

float retornaTopo (Pilha *p );

#endif // !_STACK_H

