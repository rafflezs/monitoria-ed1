#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct no{
	int dado;
	struct no *prox, *ant;
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

int verificar_lista(Lista *l){
	No *p;
	int cont=0;
	if (l->cabeca == NULL)
		return 1;

	for (p=l->cabeca; p->prox!=NULL; p=p->prox){
		cont++;	
	}

	for ( ; p->ant!=NULL; p=p->ant){
		cont--;
	}

	if (cont == 0)
		return 1;

	return 0;
}

int * obter_maior_elemento(Lista *l){
	if (l->cabeca == NULL)
		return NULL;

	No *p, *maior;
	maior = l->cabeca;
	for (p=l->cabeca->prox; p!=NULL; p=p->prox){
		if (p->dado > maior->dado)
			maior = p;
	}
	return &maior->dado;
}

int trocar_itens(Lista *l, int pos1, int pos2){
	if (l->cabeca == NULL)
		return 0;
	
	if (pos1 < 0 || pos2 < 0)
		return 0;

	int cont;
	No *p1=NULL, *p2=NULL, *p;
	for (p=l->cabeca, cont=0; p!=NULL; p=p->prox, cont++){
		if (cont == pos1){
			p1 = p;
		}
		if (cont == pos2){
			p2 = p;
		}
		if (p1 != NULL && p2 != NULL)
			break;
	}
	if (p == NULL)	// Percorreu a lista e não conseguiu posicionar os ponteiros p1 e p2
		return 0;

	int aux;
	aux = p1->dado;
	p1->dado = p2->dado;
	p2->dado = aux;

	return 1;
}

int inserir_inicio(Lista *lista, int valor){
	No *novo;

	novo = (No *) malloc(sizeof(No));
	if (novo == NULL)
		return 0;

	novo->dado = valor;
	novo->prox = NULL;
	novo->ant = NULL;

	if (lista->cabeca == NULL)
		lista->cabeca = novo;
	else{
		novo->prox = lista->cabeca;
		lista->cabeca = novo;	
		novo->prox->ant = novo;
	}
	return 1;
}

//revisar
int inserir_antes(Lista *l, int vlr_b, int vlr_i){
	if (l->cabeca == NULL)
		return 0;

	No *p, *q;
	q = NULL;
	for (p=l->cabeca; p!=NULL; p=p->prox){
		if (p->dado == vlr_b)
			break;
		q = p;
	}
	if (p == NULL)	// Elemento buscado não foi encontrado.
		return 0;

	//Preparação do nó a ser inserido
	No *novo;
	novo = (No *) malloc(sizeof(No));
	if (novo == NULL)
		return 0;
	novo->dado = vlr_i;
	novo->prox = NULL;
	novo->ant = NULL;

	if (q == NULL){
		novo->prox = p; //novo->prox = l->cabeca;
		l->cabeca = novo;	
		p->ant = novo;
	}else{
		novo->prox = p;
		q->prox = novo;
		novo->ant = q;
		p->ant = novo;
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
	novo->ant = NULL;

	if (lista->cabeca == NULL)
		lista->cabeca = novo;
	else{
		for(p=lista->cabeca; p->prox!=NULL; p=p->prox);
		p->prox = novo;
		novo->ant = p;
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
	if (lista->cabeca != NULL)
		lista->cabeca->ant=NULL;
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
int * buscar_elemento(Lista *l, int vlr){ }

void mostrar_lista(Lista *lista){ 
	No *p;
	
	if (lista->cabeca == NULL)
		printf("Lista vazia.\n");
	
	for(p=lista->cabeca; p!=NULL; p=p->prox){
		printf("%i\n", p->dado);
	}
}










