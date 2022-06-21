
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int menu(){
	int opc;
	system("clear");
	printf("[0] - Sair.\n");
	printf("[1] - criar a lista.\n");
	printf("[2] - remover a lista.\n");
	printf("[3] - Inserir no início.\n");
	printf("[4] - Inserir no fim.\n");
	printf("[5] - Inserir ordenado.\n");
	printf("[6] - Inserir apos.\n");
	printf("[7] - Remover no fim.\n");
	printf("[8] - Remover no inicio.\n");
	printf("[15] - Mostrar lista.\n\n");

	printf("Escolha uma opção: ");
	scanf("%i", &opc);
	return opc;
}

int main(){
	Lista *L1=NULL;
	int opc, valor, vlr_b;

	while(opc = menu()){
		switch(opc){
			case 1:
				L1 = criar_lista();
				if (L1)
					printf("Lista criada com sucesso.\n");
				else
					printf("Erro ao criar a lista");
				break;

			case 2:

			case 3:
				printf("valor: ");
				scanf("%i", &valor);
				if (inserir_inicio(L1, valor))
					printf("Elemento %i inserido.\n", valor);
				else
					printf("Não foi possível inserir o elemento %i.\n", valor);
				break;

			case 4:
				printf("valor: ");
				scanf("%i", &valor);
				if (inserir_fim(L1, valor))
					printf("Elemento %i inserido.\n", valor);
				else
					printf("Não foi possível inserir o elemento %i.\n", valor);
				break;

			case 6:
				printf("elemento para buscar: ");
				scanf("%i", &vlr_b);
				printf("valor: ");
				scanf("%i", &valor);
				if (inserir_apos(L1, vlr_b, valor))
					printf("Elemento %i inserido.\n", valor);
				else
					printf("Não foi possível inserir o elemento %i.\n", valor);
				break;

			case 7:
				if (remover_fim(L1))
					printf("Elemento removido.\n");
				else
					printf("Não foi possível remover.\n");
				break;

			case 8:
				if (remover_inicio(L1))
					printf("Elemento removido.\n");
				else
					printf("Não foi possível remover.\n");
				break;

			case 15:
				mostrar_lista(L1);
				break;
			
			default:
				printf("Opção inválida.\n");
		}
		getchar();
		getchar();

	}
	


}
