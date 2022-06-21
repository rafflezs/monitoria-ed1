#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int dado;
	struct no *prox, *ant;
}No;

typedef struct desc{
	No *ini, *fim;
}Desc;

No *criar_no(int vlr){
	No *novo;
	novo = (No *)malloc(sizeof(No));
	novo->dado = vlr;
	novo->prox = NULL;
	novo->ant = NULL;

	return novo;
}

void inserir_ini(Desc *d, int vlr){
	No *novo = criar_no(vlr);
	
	if (d->ini == NULL){
		d->ini = novo;
		d->fim = novo;
	}else{
		novo->prox = d->ini;
		d->ini->ant = novo;
		d->ini = novo;
	}
}

void mostrar_lista(Desc *d){
	No *p;
	for (p=d->ini; p!=NULL; p=p->prox)
		printf("%i\n", p->dado);
}

int verificar_lista(Desc *d){
	No *p;
	int cont=0;
	for (p=d->ini; p!=NULL; p=p->prox)
		cont++;
	for (p=d->fim; p!=NULL; p=p->ant)
		cont--;
	if (cont == 0)
		return 1;
	else
		return 0;
}

void inserir_fim(Desc *d, int vlr){
	No *novo = criar_no(vlr);

	if (d->ini == NULL){
		d->ini = novo;
		d->fim = novo;
	}else{
		novo->ant = d->fim;
		d->fim->prox = novo;
		d->fim = novo;
	}
}

int remover_ini(Desc *d){
	if (d->ini == NULL)
		return 0;
	No *p;
	p = d->ini;
	d->ini = p->prox;
	if (d->ini == NULL)
		d->fim = NULL;
	else
		d->ini->ant = NULL;
	free(p);
	return 1;
}

int remover_fim(Desc *d){
	if (d->ini == NULL)
		return 0;
	No *p;
	p = d->fim;
	d->fim = p->ant;
	if (d->fim == NULL)
		d->ini = NULL;
	else
		d->fim->prox = NULL;
	free(p);
	return 1;
}

int main(){
	Desc d;
	
	//inicializando o descritor
	d.ini = NULL;
	d.fim = NULL;

	inserir_fim(&d, 10);
	mostrar_lista(&d);

	printf("novo elemento.\n");
	inserir_fim(&d, 20);
	mostrar_lista(&d);

	printf("-> %i\n", verificar_lista(&d));
}




