#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int menu(){
	int opc;

	system("clear");
	printf("[0] - Sair\n");
	printf("[1] - Criar a Fila\n");
	printf("[2] - Enfileirar\n");
	printf("[3] - Desenfileirar\n");
	printf("[4] - Mostrar\n\n");

	printf("Opção: ");
	scanf("%i", &opc);
	return opc;
}

/*
FilaP * criar_fila();
int * primeiro(FilaP *fila);
int enfileirar(FilaP *fila, int valor, int prioridade);
int desenfileirar(FilaP *fila);
void remover_fila(FilaP **fila);
void limpar_fila(FilaP *fila);
int tamanho_da_fila(FilaP *fila);
int fila_vazia(FilaP *fila);
int fila_cheia(FilaP *fila);
void mostrar_fila(FilaP *fila);
*/

int main(){
	FilaP *f=NULL;
	int opc;
	int valor, prioridade;

	while(opc = menu()){
		switch(opc){
			case 1:
				if (f==NULL){
					f = criar_fila();
					printf("Fila criada com sucesso.\n");
				}
				else{
					printf("Fila já criada.\n");
				}
			break;
			case 2:
				printf("Valor: ");
				scanf("%i", &valor);
				printf("Prioridade: ");
				scanf("%i", &prioridade);
				if (enfileirar(f, valor, prioridade)){
					printf("Elemento %i enfileirado com prioridade %i.\n", valor, prioridade);	
				}
				else{
					printf("Fila cheia.\n");	
				}
			break;
			case 4:
				mostrar_fila(f);
			break;
		}
		getchar();
		getchar();
	}	
	
}

