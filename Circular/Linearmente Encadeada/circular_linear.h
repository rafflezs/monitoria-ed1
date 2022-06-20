#ifndef CIRCULAR_LINEAR_H
#define CIRCULAR_LINEAR_H

#include <stdlib.h>
#include <stdio.h>

typedef struct list List;
typedef struct node Node;

List * createList();

Node* startNode(int value);

int insertAt(List* list, int value);
int insertBegin(List* list, int value);
int insertEnd(List* list, int value);

int removeAt(List* list, int value);
int removeByValue(List* list, int value);
int removeBegin(List* list);
int removeEnd(List* list);

void display(List* list);

int search(List* list, int value);
void hasValue(List* list, int value);

int deleteList(List* list);

Node* retrieveNodeByValue(List* list, int value);
Node* retrieveNodeByIndex(List* list, int index);

#endif // !CIRCULAR_LINEAR_H