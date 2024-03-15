#include "stack.h"
#include <iostream>

using namespace std;

const int HEX = 16;
const char HEX_ARRAY [] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};


struct Stack
{
    int sp; // declaration of stack pointer
    int size; // size of Data array
    Data *array; // array of data
};

void create(Stack *&s, int capacity)
{
    s = new (nothrow) Stack; // creating of structure Stack
    s->sp = -1; // assigns to sp value -1
    s->size = capacity; 
    s->array = new (nothrow) Data[s->size]; // creates array with size equal to capacity
}   

void destroy(Stack *&s)
{
    delete [] s->array; // we need to delete because it's pointer to array
    s->array = nullptr; //we set it to nullptr so we can't manipulate with deleted array
    delete s; //deletes stack
    s = nullptr; // it doesn't point to memory that doesn't belong to us
}

void push(Stack *s, Data d)
{
    if (!full(s))
    {
        s->sp++;
        s->array[s->sp] = d; //assigns value data to position s.sp
    } else {
        cout << "Error: Stack is full" << endl;
    }
}

void pop(Stack *s)
{
    if(!empty(s))
    {
        //s->array[s->sp] = 0; //sets data on position sp to zero
        s->sp--; // lowers the number of usable elements in array
    } else {
        cout << " Error: Stack is empty" << endl;
    }
}

Data top(Stack *s)
{
    if(!empty(s))
    {
        return s->array[s->sp]; //returns value of the top element
    } else {
        cout << " Error: Stack is empty" << endl;
        return 0;
    }
}


bool empty(Stack *s)
{
    if(s->sp == -1) 
    {
        return true;
    } else {
        return false;
    }
    // return s->sp == -1;
}

bool full(Stack *s)
{
    if(s->sp == s->size -1)
    {
        return true;
    } else {
        return false;
    }
    // return !(s->sp == s->size -1);
}

void print(Stack *s)
{
    cout << "Hex value of number: "; 
    while(!empty(s))
    {
        cout << HEX_ARRAY[top(s)];
        pop(s); 
    }
    cout << endl;
}

void convertToHex(Stack *s, Data input)
{
    while (input >= HEX)
    {
        int hexValue = input % HEX;
        push(s, hexValue);
        input /= HEX; 
    }
    push(s, input % HEX);
}

