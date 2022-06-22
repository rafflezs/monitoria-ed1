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
int sortearInicial(Circulo* c, int n){
  Soldado* tmp = sortearProximo(c, n);
  c->primeiro = tmp;
}

//** Main Loop (gerar roda de Josephus)
void iniciarRodaDeJosephus(Circulo* c, int n){
  if (c == NULL || c->primeiro == NULL) {
    return;
  }

  while (c->primeiro->proximo != c->primeiro)
  {
    Soldado* s = sortearProximo(c,n);
    printf("O soldado %d foi eliminado\n", s->id);
    removerSoldado(c,s);
  }
  printf("O soldado selecionado para buscar reforços foi o Soldado %d\n", c->primeiro->id);

  c = NULL;
  printf("\n------ A lista foi esvaziada ------\n");

}

int removerSoldado(Circulo* c, Soldado* s){
  if (c == NULL || c->primeiro == NULL) {
    return 0;
  }

  Soldado* aux = c->primeiro;
  while (aux->proximo != s)
  {
    aux = aux->proximo;
  }

  aux->proximo = s->proximo;
  c->primeiro = s->proximo;
  s->proximo = NULL;

  s = NULL;

  return 1;
}

Soldado* sortearProximo(Circulo* c, int n){
  
  if (c == NULL || c->primeiro == NULL) {
    printf("Lista não instânciada!\n");
    return NULL;
  }

  
  Soldado* tmp = c->primeiro;
  for (int i = 0; i < n; i++) {
    tmp = tmp->proximo;
  }

  return tmp;
}

//** Display
void exibirSoldados(Circulo* c){

  if (c == NULL || c->primeiro == NULL) {
    printf("Lista não instânciada!\n");
    return;
  }

  Soldado* it = c->primeiro;
  do  {
    printf("Soldado %d\n",it->id);
    // printf("Proximo: soldado %d\n",it->proximo->id);
    it = it->proximo;
  } while (it != c->primeiro);
}