#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int dado;
	struct no *prox, *ant;
}No;

typedef struct desc{
	int qtd;
	No *ini, *fim, *maior;
	
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
		d->maior = novo;
		d->fim = novo;
	}else{
		novo->prox = d->ini;
		d->ini->ant = novo;
		d->ini = novo;	
		if (novo->dado > d->maior->dado)
			d->maior = novo;
	}
	d->qtd++;
}

void mostrar_lista(Desc *d){
	No *p;
	if (d->ini == NULL){
		printf("Lista vazia.\n");
		return;
	}
	printf("Qtd: %i\n", d->qtd);
	printf("Maior: %i\n", d->maior->dado);
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

// Possível Resposta da Verificação da Aprendizagem (Questão 6)
int remover_fim(Desc *d){
	if (d->ini == NULL)
		return 0;

	if (d->qtd == 1){
		No *p;
		p = d->ini;
		d->ini = NULL;
		d->fim = NULL;
		d->qtd = 0;
		d->maior = NULL;
		free(p);
		return 1;
	}
	No *p;
	p=d->fim;
	d->fim = p->ant;
	d->fim->prox = NULL;

	if (p == d->maior){ // Precisa atualizar o maior
		No *q;
		d->maior = d->ini;
		for (q=d->ini->prox; q!=NULL; q=q->prox){
			if (q->dado > d->maior->dado)
				d->maior = q;
		}
	}
	d->qtd--;
	free(p);
	return 1;
}

int main(){
	Desc d;
	
	//inicializando o descritor
	d.ini = NULL;
	d.maior = NULL;
	d.fim = NULL;
	d.qtd = 0;

	inserir_ini(&d, 100);
	inserir_ini(&d, 10);
	inserir_ini(&d, 20);

	mostrar_lista(&d);

	remover_fim(&d);
	printf("após remoção fim.\n");
	mostrar_lista(&d);

	remover_fim(&d);
	printf("após remoção fim.\n");
	mostrar_lista(&d);

	remover_fim(&d);
	printf("após remoção fim.\n");
	mostrar_lista(&d);


	printf("-> %i\n", verificar_lista(&d));
}




