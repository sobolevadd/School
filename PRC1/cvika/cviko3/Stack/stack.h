#ifndef STACK_H
#define STACK_H  

#include "datatype.h"

struct Stack; //forward declaration of Stact

void create(Stack *&s, int capacity); //creates empty stack            *&  ukazatel odkazem
void destroy(Stack *&s); //destroys stack

void push(Stack *s, Data d); //pushes data on top of the stack
void pop(Stack *s); //remove data from top
Data top(Stack *s); //returns data from top

bool empty(Stack *s); //tests if the stack is empty
bool full(Stack *s); //tests if the stack is full

#endif // STACK_H