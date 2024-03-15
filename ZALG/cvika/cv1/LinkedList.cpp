#include <iostream>
using namespace std;

struct myData
{
    string name;
    int red;
    int green;
    int blue;
    myData* next = nullptr;

    myData (string n = "", int r = 0, int g = 0, int b = 0) 
            :
            name(n), red (r), green (g), blue (b), next (NULL) 
    { }
};

myData *list;

void push(myData *&list, myData *t)
{
    t->next = nullptr;
    if (list == nullptr)
    {
        list = t;
    } else
    {
        myData* u = list; 
        while (u->next != nullptr) u = u->next;
        u->next = t;
    }
}; 

void myPrint(myData *&list)
{
    for (myData *tmp = list; tmp != nullptr; tmp = tmp->next)
    {
        cout << "Name: " << tmp->name << endl;
        cout << "RGB: " << tmp->red << " " << tmp->green << " " << tmp->blue << endl << endl;
    }
}

myData* main_list = nullptr;
myData* another_list = nullptr;

int main()
{
    list = nullptr;
    push (main_list, new myData("red" , 255, 0, 0));
    push (main_list, new myData("green" , 0, 255, 0));
    myPrint(main_list);
}


/*
struct myList
{
    myData *first;
};
*/

/*
myList* createList()
{
    myList *l = new (nothrow) myList;
    if (!l){
        return nullptr;
    }

    myData *tmp = new (nothrow) myData;
    if (!tmp){
        return nullptr;
    }

    l->first = tmp;
    l->first->next = nullptr;
    return l;
}

int main()
{
    myList* l;
    l = createList();
}
*/

/*
myList* createList()
{
    myList* list = new myList;
    list.first = nullptr;
    return list;
};


int main()
{
    myList list;
    list.first = nullptr;

    myList* l;
    l = createList();


    myData *list;
    list = nullptr;
}

*/

/*
#include <iostream>
using namespace std;
 
struct Item;
 
struct List
{
    Item * first;
    Item * last;
};
 
struct Item
{
    string name;
    int    r, g, b;
    Item * next;
};
 
void init (List & a) // prazdny seznam
{
    a.first = nullptr;
    a.last = nullptr;
}
 
void insertFirst (List & a, string name0, int r0, int g0, int b0)
{
    Item* t = new Item;
 
    t->name = name0;
    t->r = r0;
    t->g = g0;
    t->b = b0;
 
    t->next = a.first; // za novym prvkem bude dosud prvni prvek
 
    a.first = t; // prvni bude novy prvek
 
    if (a.last == nullptr)
        a.last = t; // pokud je seznam prazdny tak i posledni bude novy prvek
}
 
void insertLast (List & a, string name0, int r0, int g0, int b0)
{
    Item* t = new Item;
 
    t->name = name0;
    t->r = r0;
    t->g = g0;
    t->b = b0;
 
    t->next = nullptr; // nikdo za novym prvkem nebude
 
    if (a.last != nullptr) // pokud seznam neni prazdny
        a.last->next = t; // pripojime novy prvek za posledni prvek
 
    a.last = t; // posledni bude novy prvek
 
    if (a.first == nullptr) // pokud byl seznam prazdny
        a.first = t; // prvni bude take novy prvek
}
 
void print (List & a)
{
    Item* t = a.first;
    while (t != nullptr)
    {
        cout << t->name << " " << t->r << "," << t->g << "," << t->b << endl;
        t = t->next;
    }
}
 
int main ()
{
    List a; // promenna pro nas seznam
    init (a);
 
    insertLast (a, "cervena", 255, 0, 0);
    insertLast (a, "zelena", 0, 255, 0);
    insertLast (a, "modra", 0, 0, 255);
 
    print (a);
    return 0;
}
*/



