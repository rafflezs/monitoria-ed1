#include "circular_linear.h"

struct list {
  struct node *header;
};

struct node {
  struct node *next;
  int value;
};

List * createList(){
	List *list;
	list = (List *)malloc(sizeof(List));
	if (list == NULL)
		return NULL;

	list->header = NULL;
	return list;
}

Node* startNode(int value){
  Node* newNode = (Node*) malloc(sizeof(Node));
  newNode->value = value;
  newNode->next = NULL;

  return newNode;
}

Node* last(List* list) {
  if (list == NULL) {
    return NULL;
  }

  if (list->header->next == list->header) {
    return list->header;
  }

  Node* aux = list->header;
  while (aux->next != list->header)
  {
    aux = aux->next;
  }
  return aux;
}

// Node* retrieveNodeByValue(List* list, int value){

// }

// Node* retrieveNodeByIndex(List* list, int index){

// }

// int insertAt(List* list, int value){

// }

// ! O imbecil aqui acabou de lembrar que so existe INSERT em 
// ! lista circular, pois inserir no inicio ou no final é
// ! Idempotente, visto que o head sempre aponta pro tail

int insertBegin(List* list, int value){
  
  if (list->header == NULL) {
    Node* aux = startNode(value);
    aux->next = aux;
    list->header = aux;
    return 1;
  } else {


  Node* aux = startNode(value);
  aux->next = list->header;
  Node* lastNode = last(list);
  lastNode->next = aux;
  list->header = aux;
  return 1;
  }
}

int insertEnd(List* list, int value){

  if (list->header == NULL) {
    Node* aux = startNode(value);
    aux->next = aux;
    list->header = aux;
    return 1;
  } 

  Node* aux = last(list);
  Node* newNode = startNode(value);
  aux->next = newNode;
  newNode->next = list->header;
}

// int removeAt(List* list, int value){

// }

int removeBegin(List* list){

  if (list->header == list->header->next) {
    list->header = NULL;
    list = NULL;
    deleteList(list);
    return 1;
  }

  Node* aux = list->header;

  Node* lastNode = last(list);
  list->header = list->header->next;
  lastNode->next = list->header;

  aux = NULL;
  free(aux);

  return 1;
}

int removeEnd(List* list){

  if (list->header == list->header->next) {
    list->header = NULL;
    list = NULL;
    deleteList(list);
    return 1;
  }

  Node* aux = list->header;
  while (aux->next->next != list->header)
  {
    aux = aux->next;
  }
  Node* lastNode = aux->next;
  aux->next = list->header;
  
  lastNode = NULL;
  free(lastNode);
}

void display(List* list){
  if (list->header == NULL) {
    printf("Empty List - NULL VALUE for %s\n", list);
    return;
  }

  Node* aux = list->header;
  int i = 0;
  do
  {
    printf("index: %d - valor [%d] | ", i , aux->value);
    aux = aux->next;
    i += 1;
  } while (aux != list->header);
  

  printf("\n");
}

void search(List* list, int value){

  if (list->header == list->header->next) {
    if (list->header->value == value) {
      printf("A primeira ocorrência do valor [%d] foi encontrado na posição 0", value);
    }
  }

  int i = 0;
  for (Node* aux = list->header; aux = aux->next) {
    if (aux->value == value) {
      printf("A primeira ocorrência do valor [%d] foi encontrado na posição %d", value, i);
    }
    i++;
  }
}

int deleteList(List* list){
  free(list);
}