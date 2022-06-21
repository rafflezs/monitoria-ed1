#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int menu(){
	int opc;
	system("clear");
	printf("[0] - sair.\n");
	printf("[1] - criar a lista.\n");
	printf("[2] - inserir no início.\n");
	printf("[3] - mostrar lista.\n\n");

	printf("Escolha uma opção: ");	
	scanf("%i", &opc);
	return opc;
}

int main(){
	Lista *l;
	int opc, vlr;

	while(opc = menu()){
		switch(opc){
			case 1:
				l = criar_lista();
				printf("Lista criada.\n");
				break;
			case 2:
				printf("valor: ");
				scanf("%i", &vlr);
				if (inserir_inicio(l, vlr))
					printf("%i inserido.\n", vlr);
				else
					printf("falha ao inserir %i.\n", vlr);
				break;
			case 3:
				mostrar_lista(l);
				break;
			default:
				printf("Opção inválida.\n");				
		}
		getchar();
		getchar();
	}
}






