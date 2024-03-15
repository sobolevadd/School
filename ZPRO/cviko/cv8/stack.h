#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED


typedef int Data;
/*
struct Stack{
    int capacity; //max pocet prvku
    int sp; // index na vrchol zasobniku, stack pointer
    Data *data; // ukazatel na dynamicky alokovane pole s uzitecnymi data
};
*/ //aby uzivatel nemel pristup, presun do cpp

struct Stack;

//vytvori prazdny zasobnik s pozadavanou kapacitou
Stack* createStack (int size);

void destroyStack(Stack *&s);
//vlozi data d na vrchol zasobniku
void push(Stack *s, int d);
//odstarni vrchol
void pop(Stack *s);
//vraci data z vrcholu
Data top(Stack *s);

//test prazdnost
bool isEmpty(Stack *s);
//test platnosti
bool isFull(Stack *s);
//vrati kapacitu
#endif