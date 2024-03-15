#include <iostream>
#include <assert.h>
using namespace std;

enum{OK};

class Item;

class List
{
public:
    Item * first = nullptr;
    Item * last = nullptr;

private:
    void insert (Item * before, Item * fresh, Item * after);
       
public:
    void insertFirst (Item* fresh);
    void insertLast (Item* fresh);

    void print();

    List () { }
    ~List ();

    friend class Item;

};

/*
class List
{
private:
    Item * first = nullptr;
    Item * last = nullptr;

public:
    Item * getFirst() { return first;}
    Item * getLast() { return last;}

private:
    void insert (Item * before, Item * fresh, Item * after);
        friend class Item;

};*/

List::~List()
{
    Item* p = first;
    while (p != first)
    {
        Item* t = p->next;
        
    }
}

class Item
{
public:
    List* link;
    string name;
    int r, g, b;
    Item * prev;
    Item * next;
    Item(string name0 = " ", int r0 = 0, int g0 = 0, int b0 = 0): name(name0), r(r0), g(g0), b(b0), prev(nullptr), next(nullptr){}

    void insertAfter (Item* fresh);
    void insertBefore (Item* fresh);
};

void List::insert (Item * before, Item * fresh, Item * after)
{
    //assert (first == nullptr && last == nullptr || first != nullptr && last !- nullptr);
    assert (fresh != nullptr);
    assert(fresh->link == nullptr);
    fresh->link = this;
    
    fresh->prev = before;
    fresh->next = after;
    
    if (before != 0)
    {   
        before->next = fresh;
    } else 
    {
        first = fresh;
    }

    if (after)
    {
        after->prev = fresh;
    } else 
    {
        last = fresh;
    }
}

void List::insertFirst (Item* fresh)
{
    insert (nullptr, fresh, first);
}

void List::insertLast (Item* fresh)
{
    insert (last, fresh, nullptr);
}

void Item::insertAfter (Item* fresh)
{
    this->link->insert (this, fresh, this->next);
}

void Item::insertBefore (Item* fresh)
{
    link->insert (this, fresh, this->next);
}

void List::print()
{
    cout << "Begin of the list" << endl;
    Item * p = first;
    while (p != nullptr)
    {
        cout << p->name << ", " << p->r << ", " << p->g << ", " << p->b << endl;
        p = p->next;
    }
    cout << "End of the list" << endl;
}

List l;

int main()
{
    l.insertFirst (new Item("red", 255, 0, 0));
    l.insertLast (new Item("green", 0, 255, 0));

    l.first->insertAfter
    List l;
    return OK;
}