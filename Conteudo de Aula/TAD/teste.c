#include<stdio.h>

int main(){
	char str[10] = "teste";
	char *ptr;

	ptr= str; // prt = &str[0];

	ptr = ptr+2;

	printf("%c\n", ptr[-3]);
}
