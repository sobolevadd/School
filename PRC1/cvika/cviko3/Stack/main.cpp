#include <iostream>
#include "stack.h"

using namespace std;

int main ()
{
    const int N = 10;
    int i = 1;
    Stack *s;
    create(s, N);
    
    while(!full(s))
    {
        push(s, i);
        i++;
    }

    //s->sp = -1; nevypise nic
    //s->sp = 100; budu sahat do pameti ktera me nepatri
    //s->array[4] = 20; prepise 4. polozku (pocita se od nuly) 
    // co znamena ze muzu sahat do te structury, kvuli tomu to neni pouzitelny
    // proto prekopirujeme struct Stack y stack.h do stack.cpp, a udelame forward declaration in stack.h

    while(!empty(s))
    {
        cout << top(s) <<endl;
        pop(s);
    }
    
    destroy(s);

    // int i = 5;
    // cout << i++ <<endl;
    // cout <<i << endl; // 5 6
    // cout << ++i << endl;
    // cout << i << endl; //7 7
    
    return 0;
}