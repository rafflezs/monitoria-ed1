#include<stdio.h>
#include<stdlib.h>

typedef struct no{
	int dado;
	struct no *prox;
}No;

void inserir(No **l, int vlr){
	No *novo;
	novo = (No *)malloc(sizeof(No));
	novo->dado = vlr;
	novo->prox = NULL;

	if (*l == NULL){
		*l = novo;
		novo->prox = novo;
	}else{
		novo->prox = (*l)->prox;
		(*l)->prox = novo;
	}
}

void inserir_ini(No **l, int vlr){
	No *novo;
	novo = (No *)malloc(sizeof(No));
	novo->dado = vlr;
	novo->prox = NULL;

	if (*l == NULL){
		*l = novo;
		novo->prox = novo;
	}else{
		No *p;
		for (p=*l; p->prox!=*l; p=p->prox);
		p->prox = novo;
		novo->prox = *l;
		*l = novo;	
	}	
}

void inserir_fim(No **l, int vlr){
	No *novo;
	novo = (No *)malloc(sizeof(No));
	novo->dado = vlr;
	novo->prox = NULL;

	if (*l == NULL){
		*l = novo;
		novo->prox = novo;
	}else{
		No *p;
		for (p=*l; p->prox!=*l; p=p->prox);
		p->prox = novo;
		novo->prox = *l;		
	}
}

void mostrar(No **l){
	No *p;
	if (*l == NULL){
		printf("Lista vazia.\n");
		return;
	}

	for (p=*l; p->prox!=*l ; p=p->prox)
		printf("%i\n", p->dado);
	printf("%i\n", p->dado);
}

int existe_vlr(No **l, int vlr){
	if (*l == NULL)
		return 0;
	No *p;
	for(p=*l; p->prox!=*l; p=p->prox){
		if (p->dado == vlr)
			return 1;
	}
	if (p->dado == vlr)
		return 1;	
	return 0;
}

int main(){
	No *l1;
	l1 = NULL;	// inicializando a lista

	inserir(&l1, 10);
	inserir(&l1, 20);
	inserir(&l1, 30);

	mostrar(&l1);

	printf("--> %i\n", existe_vlr(&l1, 300));
	
}
