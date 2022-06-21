#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#define TAM 10

struct lista{
	int vet[TAM];
	int qtd;	
};

int verificar_lista(Lista *l, char *msg){
	if (l==NULL){
		printf("lista nula: %s\n", msg);
		return 0;
	}
	return 1;
}

Lista * criar_lista(){
	Lista *l;
	l = (Lista *) malloc(sizeof(Lista));
	if (l == NULL){
		printf("falha ao alocar a lista.\n");
		exit(1);
	}
	l->qtd = 0;
	return l;
}

void deslocar_direita(Lista *l){
	for (int i=l->qtd; i>0; i--){
		l->vet[i] = l->vet[i-1];
	}
}

int inserir_inicio(Lista *l, int vlr){
	if (verificar_lista(l, "inserir_inicio")){
		// verificar se o novo elmento cabe na lista
		if (l->qtd == TAM)
			return 0;

		deslocar_direita(l);
		l->vet[0] = vlr;
		l->qtd++;
		return 1;
	}
	return 0;
}

void mostrar_lista(Lista *l){
	if (verificar_lista(l, "mostrar_lista")){
		if (l->qtd == 0){
			printf("Lista vazia.\n");
			return;
		}
		for (int i=0; i<l->qtd; i++){
			printf("%i\n", l->vet[i]);
		}
	}
}






