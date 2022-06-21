#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int dado;
	struct no *prox;
}No;

void inserir_ini(No **cabeca, int vlr){
	No *novo;
	novo = (No *)malloc(sizeof(No));
	novo->dado = vlr;
	novo->prox = NULL;

	if (*cabeca == NULL)
		*cabeca = novo;
	else{
		novo->prox = *cabeca;
		*cabeca = novo;
	}
}

// Possível Respo. da Verificação da Aprendizagem (Questão 5a)
void concatenar(No **l1, No **l2){
	if (*l2 == NULL)
		return;
	if (*l1 == NULL){
		*l1 = *l2;
		*l2 = NULL;
		return;
	}
	No *p;
	for(p=*l1;p->prox!=NULL;p=p->prox);
	p->prox = *l2;
	*l2 = NULL;
}

void mostrar(No **cabeca){
	No *p;	
	for(p=*cabeca; p!=NULL; p=p->prox){
		printf("%i\n", p->dado);
	}
}

// Possível Respo. da Verificação da Aprendizagem (Questão 5b)
int existe_n(No **cabeca, int vlr){
	No *p;
	for (p=*cabeca; p!=NULL; p=p->prox){
		if (p->dado == vlr)
			return 1;
	}
	return 0;
}

int main(){
	No *l1=NULL;
	No *l2=NULL;

	inserir_ini(&l1, 10);
	inserir_ini(&l1, 20);
	inserir_ini(&l1, 30);

	printf("lista 1\n");
	mostrar(&l1);

	inserir_ini(&l2, 100);
	inserir_ini(&l2, 200);
	inserir_ini(&l2, 300);

	printf("lista 2\n");
	mostrar(&l2);

	concatenar(&l1, &l2);

	printf("Resultado da Concatenação\n");
	mostrar(&l1);

	printf("-->%i\n", existe_n(&l1, 200));

}



