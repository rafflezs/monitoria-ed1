#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

typedef struct no{
	int dado;
	int prioridade;
	struct no *prox;
}No;

struct filaP{
	No *cabeca;
};

FilaP * criar_fila(){
	FilaP *fila;
	fila = (FilaP *)malloc(sizeof(FilaP));
	if (fila == NULL)
		return NULL;
	fila->cabeca = NULL;
	return fila;
}

int enfileirar(FilaP *fila, int valor, int prioridade){

	if (fila == NULL){
		printf("Falha ao enfileirar. Tentativa de enfileirar sem antes criar a fila.\n");
		exit(0);
	}

	No *novo;
	novo = (No *)malloc(sizeof(No));
	if (novo == NULL)
		return 0;
	novo->dado = valor;
	novo->prioridade = prioridade;
	novo->prox = NULL;

	if (fila->cabeca==NULL){
		fila->cabeca = novo;
		return 1;
	}

	No *p, *q;
	q=NULL;
	for (p=fila->cabeca; p!=NULL; p=p->prox){
		if (prioridade >= p->prioridade){
			break;
		}
		q=p;
	}
	if (q == NULL){ // inserção no início
		novo->prox = fila->cabeca;
		fila->cabeca = novo;
		return 1;
	}
	if (p == NULL){ // inserção no fim
		q->prox = novo;
		return 1;
	}
	// inserção no meio
	q->prox = novo;
	novo->prox = p;

	return 1;
}

void mostrar_fila(FilaP *fila){

	if (fila == NULL){
		printf("Falha ao tentar mostrar a fila sem antes criar a estrutura.\n");
		exit(0);
	}

	if (fila->cabeca == NULL)
		printf("Fila Vazia.\n");
	else{
		No *p;
		for(p=fila->cabeca; p!=NULL; p=p->prox){
			printf("%i(%i) ", p->dado, p->prioridade);
		}
		printf("\n");
	}

}

