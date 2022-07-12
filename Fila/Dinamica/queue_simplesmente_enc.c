#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int dado;
	struct no *prox;
}No;

typedef struct desc{
	No *ini, *fim;
}Desc;

// Inserir no fim de uma llse com descritor
int enfileirar(Desc *D, int vlr){
	No *novo;
	novo = (No*) malloc(sizeof(No));
	if (novo == NULL)
		return 0;
	novo->dado = vlr;
	novo->prox = NULL;

	if (D->ini == NULL){
		D->ini = novo;
		D->fim = novo;
	}else{
		D->fim->prox = novo;
		D->fim = novo;
	}	

	return 1;
}

// Remover no início de uma llse com descritor
int desenfileirar(Desc *D){
	if (D->ini == NULL)
		return 0;
	
	No *p;
	p = D->ini;
	D->ini = p->prox;	
	free(p);
	if (D->ini == NULL)
		D->fim = NULL;

	return 1;
}

int * primeiro(Desc *D){
	if (D->ini == NULL)
		return NULL;

	return &D->ini->dado;
}

void mostrar_llse_desc(Desc *D){
	if (D->ini == NULL)
		printf("Lista vazia.\n");
	else{
		No *p;
		for (p=D->ini; p!=NULL; p=p->prox){
			printf("%i\n", p->dado);
		}
	}
}

int main(){
	Desc D;
	D.ini = NULL;	// inicialização
	D.fim = NULL;
	int *aux;

	enfileirar(&D, 10);
	enfileirar(&D, 20);
	enfileirar(&D, 30);
	printf("Lista apos inserção.\n");
	mostrar_llse_desc(&D);
	aux = primeiro(&D);
	if (aux != NULL)
		printf("Primeiro da fila: %i\n", *aux);
	else
		printf("Fila vazia.\n");

	printf("Lista apos remoção.\n");
	desenfileirar(&D);
	mostrar_llse_desc(&D);
	aux = primeiro(&D);
	if (aux != NULL)
		printf("Primeiro da fila: %i\n", *aux);
	else
		printf("Fila vazia.\n");


	printf("Lista apos remoção.\n");
	desenfileirar(&D);
	mostrar_llse_desc(&D);
	aux = primeiro(&D);
	if (aux != NULL)
		printf("Primeiro da fila: %i\n", *aux);
	else
		printf("Fila vazia.\n");


	printf("Lista apos remoção.\n");
	desenfileirar(&D);
	mostrar_llse_desc(&D);
	aux = primeiro(&D);
	if (aux != NULL)
		printf("Primeiro da fila: %i\n", *aux);
	else
		printf("Fila vazia.\n");


}


