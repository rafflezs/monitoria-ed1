
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
	printf("[9] - Inserir antes.\n");
	printf("[10] - Trocar elementos.\n");
	printf("[11] - Obter o maior elemento.\n");
	printf("[12] - Verificar lista.\n");
	printf("[15] - Mostrar lista.\n\n");

	printf("Escolha uma opção: ");
	scanf("%i", &opc);
	return opc;
}

int main(){
	Lista *L1=NULL;
	int opc, valor, vlr_b, pos1, pos2, *aux;

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

			case 9:
				printf("elemento para buscar: ");
				scanf("%i", &vlr_b);
				printf("valor: ");
				scanf("%i", &valor);
				if (inserir_antes(L1, vlr_b, valor))
					printf("Elemento %i inserido.\n", valor);
				else
					printf("Não foi possível inserir o elemento %i.\n", valor);
				break;


			case 10:
				printf("posição do 1º elemento: ");
				scanf("%i", &pos1);
				printf("posição do 2º elemento: ");
				scanf("%i", &pos2);
				if (trocar_itens(L1, pos1, pos2))
					printf("Elementos trocados.\n");
				else
					printf("Não foi possível trocar os elementos\n");
				break;

			case 11:
				aux = obter_maior_elemento(L1);
				if (aux == NULL)
					printf("Lista vazia. Não tem o maior elemento.\n");
				else
					printf("O maior é: %i\n",*aux); 
				break;

			case 12:
				if (verificar_lista(L1))
					printf("Lista OK.\n");
				else
					printf("Lista quebrada.\n");
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
