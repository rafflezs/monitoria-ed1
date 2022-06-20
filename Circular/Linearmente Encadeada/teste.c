#include "circular_linear.h"

int main() {

  List* l = createList();

  insertBegin(l,10);
  display(l);
  insertBegin(l,20);
  display(l);
  insertEnd(l,30);
  display(l);

  removeEnd(l);
  display(l);

  return 0;
}