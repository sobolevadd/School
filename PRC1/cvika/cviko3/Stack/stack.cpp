#include "stack.h"

struct Stack
{
    int sp; //stack pointer
    int size;
    Data *array; //useful data
};

void create(Stack *&s, int capacity)
{
    s = new Stack; //proto to pridavame odkazem, jinak by doslo k uniku pameti
    s->sp = -1;
    s->size = capacity; 
    s->array = new Data[s->size];
}

void destroy(Stack *&s)
{
    delete [] s->array;
    s->array = nullptr; 
    delete s;
    s = nullptr;
}

void push(Stack *s, Data d)
{
    if(!full(s))
    {
        s->sp++;                          //s->sp = s->sp + 1; //zvetsim pole
        s->array[s->sp] = d;              //vlozim data

        //s->array[++s->sp] = d;
    } else
    {
        //throw exception
    }
}

void pop(Stack *s)
{
    if(!empty(s))
    {
        s->sp--;
    } else {
        //throw
    }
}

Data top(Stack *s)
{
    if(!empty(s))
    {
        return s->array[s->sp];
    } else {
        //throw
    }
}

bool empty(Stack *s)
{
    return(s->sp == -1);
    
    //return((s->sp == -1) ? true : false);

    // if(s->sp == -1){
    //     return true;
    // } else {
    //     return false;
    // }
}

bool full(Stack *s)
{
    return(s->sp == s->size -1);
}