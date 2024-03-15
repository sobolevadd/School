#include "list.h"
#include <iostream>

using namespace std;

struct List{
    Item *first; //ukazatel na hlavu
    Item *last; //ukazatel na zarazku
    int itemCounter; // pocitadlo prvku
};

List* createList(){
    List *l = new(nothrow) List;
    if(!l){
        return nullptr;
    }
    l->itemCounter = 0;
    l->first = new Item;
    l->first->next = nullptr;
    l->last = l->first;
    return l;
};

//vlozeni na zacatek seznamu
bool pushFront(List *l, Data d){
    Item *ptr = new(nothrow) Item;
    ///if(ptr == nullptr){
    if(!ptr){
        return false; //neuspesne ukonceni
    }
    ptr->data = d;
    ptr->next = l->first;
    l->first = ptr;
    l->itemCounter++;
    return true;
}

bool popFront(List *l){
    //testovat prazdnost!!!
    if(isEmpty(l)){
        return false;
    }
    Item *tmp = l->first;
    l->first = tmp->next;
    delete tmp;
    l->itemCounter--;
    return true;
}

bool isEmpty(List *l){
    return (l->itemCounter == 0);
}

Data front(List *l){
    return l->first->data;
}

void print(List *l){
    for(Item *tmp = l->first; tmp != l->last; tmp = tmp->next){
        cout << tmp->data << " ";
    }
    if(isEmpty(l)){
        cout << "List is empty";
    }
    cout << "\n";
}

//smaze vsechny prvky s uzitecnymi daty
//vyuziti principu DRY(do not repeat yourself)
void clean(List *l){
    while(!isEmpty(l)){
        popFront(l);
    }
}

void destroyList(List *&l){
    clean(l);
    delete l->first;
    delete l;
    l = nullptr;
}

Item* find(List *l, Data d){
    Item *tmp = l->first; 
    l->last->data = d; 
    while (tmp->data != d){
        tmp = tmp->next;
    }
    return (tmp == l->last ? nullptr : tmp);
    /*if(tmp == l->last){
        return nullptr;
    } else{
        return tmp;
    }*/
    //podmineny vyraz P ? V1 : V2 
}

bool remove(List *l, Data d){
    Item *tmp = find(l, d);
    if(!tmp){
        return false;
    }
    //prevedeni na predchozi pripad
    tmp->data =tmp->next->data;
    removeAfter(l, tmp);
    return true;
}

//odstrani prvek lezici za prvkem where
void removeAfter(List *l, Item *where){
    Item *p = where->next; // naslednik, prvek ke smazani
    if(p == l->last){
        l->last = where;
    }
    where->next = p->next;
    delete p;
    l->itemCounter--;
}

//vlozeni na konec
bool pushBack(List *l, Data d){
    Item *ptr = new(nothrow) Item;
    if(!ptr){
        return false;
    }
    l->last->data = d;
    ptr->next = nullptr;
    l->last->next = ptr;
    l->last = ptr;
    l->itemCounter++;
    return true;
}