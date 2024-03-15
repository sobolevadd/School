#include <iostream>
#include "stack.h"

using namespace std;

struct Stack{
    int capacity; //max pocet prvku
    int sp; // index na vrchol zasobniku, stack pointer
    Data *data; // ukazatel na dynamicky alokovane pole s uzitecnymi data
};

//vytvori prazdny zasobnik s pozadavanou kapacitou
Stack* createStack (int size){
    Stack *s = new(nothrow) Stack;
    if(!s){
        return nullptr;
    }
    s->capacity = size; //(*s).capacity = size;
    s->sp = -1;
    s->data = new Data[size];
    return s;
}


//uvolni pamet zabiranou zasobnikem
void destroyStack(Stack *&s){
    delete [] s->data; //mazu pole, proto []
    delete s;
    s =nullptr;
}


//vlozi data d na vrchol zasobniku
void push(Stack *s, int d){
    if(!isFull(s)){
        //s->data[++s->sp] = d;
        s->sp++; //posune index na novy vrchol
        s->data[s->sp] = d; //na novy vrchol zapiseme data
    }else{
        //vyvolat vyjimkku
    }
}


//odstarni vrchol
void pop(Stack *s){
    if(!isEmpty(s)){
        //s->data[s->sp] = 0; //neni potreba
    s->sp--;
    } else{
        //vyjimka
    }
}


//vraci data z vrcholu
Data top(Stack *s){
    return s->data[s->sp];
}

//test prazdnost
bool isEmpty(Stack *s){
    return (s->sp == -1);
    /*if(s->sp == -1){
        return true;
    }else{
        return false;
    }*/
}


//test platnosti
bool isFull(Stack *s){
    return(s->sp == s->capacity -1);
}

//vrati kapacitu
int getSize(Stack *s){
    return s->capacity;
}

