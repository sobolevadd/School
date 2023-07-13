#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
 
#include "item.h"

//doopredna deklarace structury list
struct List;

List* createList();
Item* find(List *l, Data d);
void destroyList(List *&l);
void clean(List *l);
bool pushFront(List *, Data d);
bool pushBack(List *l, Data d);
bool popFront(List *l);
Data front(List *l);
bool isEmpty(List *l);
void print(List *l);
bool remove(List *l, Data d);
void removeAfter(List *l, Item *where);


#endif // lIST_H_INCLUDED