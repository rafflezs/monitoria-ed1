#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct no{
	int dado;
	struct no *prox;
}No;

struct lista{
	No *cabeca;
};

Lista * criar_lista(){
	Lista *lista;
	lista = (Lista *)malloc(sizeof(Lista));
	if (lista == NULL)
		return NULL;

	lista->cabeca = NULL;
	return lista;
}

int inserir_inicio(Lista *lista, int valor){
	No *novo;

	novo = (No *) malloc(sizeof(No));
	if (novo == NULL)
		return 0;

	novo->dado = valor;
	novo->prox = NULL;

	if (lista->cabeca == NULL)
		lista->cabeca = novo;
	else{
		novo->prox = lista->cabeca;
		lista->cabeca = novo;	
	}
	return 1;
}

void remover_lista(Lista **lista){ }

int inserir_fim(Lista *lista, int valor){ 
	No *novo, *p;

	novo = (No *) malloc(sizeof(No));
	if (novo == NULL)
		return 0;

	novo->dado = valor;
	novo->prox = NULL;

	if (lista->cabeca == NULL)
		lista->cabeca = novo;
	else{
		for(p=lista->cabeca; p->prox!=NULL; p=p->prox);
		p->prox = novo;
	}
	return 1;
}

int inserir_ordenado(Lista *lista, int valor){ }
int inserir_na_posicao(Lista *lista, int valor, int pos){ }
int inserir_apos(Lista *l, int vlr_b, int vlr_i){ }

int remover_inicio(Lista *lista){
	No *aux;
	if (lista->cabeca == NULL)
		return 0;
	
	aux = lista->cabeca;
	lista->cabeca = lista->cabeca->prox; //lista->cabeca = aux->prox;
	free(aux);
	return 1;
}

int remover_fim(Lista *lista){
	if (lista->cabeca == NULL)
		return 0;

	No *p, *q;
	q = NULL;
	for (p=lista->cabeca; p->prox!=NULL; p=p->prox){
		q = p;
	}
	if (q == NULL){
		free(p);
		lista->cabeca = NULL;
	}else{
		q->prox = NULL;
		free(p);
	}
	return 1;
}


int remover_por_valor(Lista *lista, int valor){ }
int remover_na_posicao(Lista *lista, int pos){ }
void concatenar_lista(Lista *lista1, Lista *lista2){ }
void intercalar_lista(Lista *lista1, Lista *lista2){ }
int buscar_elemento(Lista *lista){ }

void mostrar_lista(Lista *lista){ 
	No *p;
	
	if (lista->cabeca == NULL)
		printf("Lista vazia.\n");
	
	for(p=lista->cabeca; p!=NULL; p=p->prox){
		printf("%i\n", p->dado);
	}
}










