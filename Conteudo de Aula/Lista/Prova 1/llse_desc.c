#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int dado;
	struct no *prox;
}No;

typedef struct desc{
	No *ini, *fim;
}Desc;



void inserir_ini(Desc *d, int vlr){
	No *novo;
	novo = (No *)malloc(sizeof(No));
	if (novo == NULL){
		printf("Memória insuficiente para alocação dinâmica.\n");
		exit(0);	
	}
	novo->dado = vlr;
	novo->prox = NULL;

	if (d->ini == NULL){
		d->ini = novo;
		d->fim = novo;		
	}else{
		novo->prox = d->ini;
		d->ini = novo;
	}
}

void inserir_fim(Desc *d, int vlr){
	No *novo;
	novo = (No *)malloc(sizeof(No));
	if (novo == NULL){
		printf("Memória insuficiente para alocação dinâmica.\n");
		exit(0);	
	}
	novo->dado = vlr;
	novo->prox = NULL;

	if (d->ini == NULL){
		d->ini = novo;
	}else{
		d->fim->prox = novo;	
	}
	d->fim = novo;
}

void mostrar_lista(Desc *d){
	No *p;
	for (p=d->ini; p!=NULL; p=p->prox){
		printf("%i\n", p->dado);
	}
}

int remover_inicio(Desc *d){
	if (d->ini == NULL)
		return 0;

	No *aux;
	aux = d->ini;
	d->ini = aux->prox;
	free(aux);
	if (d->ini == NULL)
		d->fim = NULL;
	return 1;
}

int main(){
	Desc d;

	//inicializando o descritor
	d.ini = NULL;
	d.fim = NULL;

	inserir_fim(&d, 10);
	inserir_fim(&d, 20);
	inserir_fim(&d, 30);
	mostrar_lista(&d);

	printf("removeção no início.\n");
	remover_inicio(&d);
	mostrar_lista(&d);

	printf("removeção no início.\n");
	remover_inicio(&d);
	mostrar_lista(&d);

	printf("removeção no início.\n");
	remover_inicio(&d);
	mostrar_lista(&d);


}



