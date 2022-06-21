#include "../headers/data_struct.h"

struct circulo{
  Soldado* primeiro;
  int qtd;
};

struct soldado{
  char nome[30];
  int id;
  Soldado* proximo;
};

//** Instanciadores
Soldado* criarSoldado(int id){
  Soldado* novo = (Soldado*) malloc(sizeof(Soldado));
  // strcpy(novo->nome, nome);
  novo->id = id;
  novo->proximo = NULL;
  return novo;
}

Circulo* criarCirculo(){
  return (Circulo*) malloc(sizeof(Circulo));
}

Soldado* obterSoldado();

//** Inserts
int inserirSoldado(Circulo* c, Soldado* s){
  if (c == NULL){
    return 0;
  }
  
  if (c->primeiro == NULL) {
    c->primeiro = s;
    s->proximo = s;
    return 1;
  }

  Soldado* tmp = c->primeiro;
  do {
    tmp = tmp->proximo;
  } while (tmp->proximo != c->primeiro);
  
  s->proximo = tmp->proximo;
  tmp->proximo = s;
  return 1;
}

//** Parametrização
int sortearInicial(Circulo* c, int n);

//** Main Loop (gerar roda de Josephus)
void iniciarRodaDeJosephus();
int removerSoldado(Circulo* c, Soldado* s);
int sortearProximo(Circulo* c);

//** Display
void exibirSoldados(Circulo* c){

  Soldado* it = c->primeiro;
  do  {
    printf("%d - Soldado %s\n",it->id, it->nome);
    it = it->proximo;
  } while (it != c->primeiro);
}