#include<stdio.h>

struct fracao{
	int x;
	int y;
};

void ler_fracao(struct fracao *f){

	printf("numerador: ");
	scanf("%i", &f->x);

	printf("denominador: ");
	scanf("%i", &f->y);
}

int main(){
	int i;
	struct fracao var[10];

	for(i=0; i<10; i++){
		printf("lendo a fração[%i]\n", i);
		ler_fracao(&var[i]);	
	}

	for (i=0;i<10;i++)
		printf("fração:[%i] o numerador é: %i e o denominador é: %i\n", i, var[i].x, var[i].y);

}
