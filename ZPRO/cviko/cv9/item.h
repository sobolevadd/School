#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

typedef int Data;

//prvek jednosmerneho seznamu
struct Item{
    Data data; //uzitecna data
    Item *next; //ukazatel na dalsi prvek
};


#endif // ITEM_H_INCLUDED