#include <iostream>
#include <assert.h>
using namespace std;

class Item;

class List 
{

public:
// private:
    Item* first = nullptr;
    Item* last = nullptr;

public:
    Item* getFirst() { return first; }
    Item* getLast() { return last; }

private:
    void insert(Item* before, Item* fresh, Item* after); 

public:
    void insertFirst (Item* fresh);
    void insertLast(Item* fresh);

    void print ();

    Item* find (string name0);

    List () { }
    ~List();

    friend class Item;
};

class Item {
public:
    List * link;
    string name;
    int r, g, b;
    Item* prev;
    Item* next;
    Item(string name0="", int r0=0, int g0=0, int b0=0) 
        : link (nullptr), name(name0), r(r0), g(g0), b(b0), prev(nullptr), next(nullptr) { }

    void insertBefore(Item* fresh);
    void insertAfter(Item* fresh);
    void remove ();
};

List :: ~ List ()
{
    Item* p = first;
    while (p != nullptr)
    {
        Item* t = p->next;
        // p->remove();
        delete p;
        p = t;
    }
    // first = nullptr;
    // last = nullptr;
}

void List::insert(Item* before, Item* fresh, Item* after) 
{
    // assert(first == nullptr && last == nullptr || first != nullptr && last != nullptr);
    assert(fresh != nullptr);
    assert(fresh->link == nullptr);
    fresh->link = this;

    fresh->prev = before;
    fresh->next = after;

    if (before != nullptr) 
    {
        before->next = fresh;
    }
    else 
    {
       first = fresh;
    }

    if (after != nullptr) 
    {
        after->prev = fresh;
    }
    else 
    { 
        last = fresh; 
    }
};

void Item::remove()
{
    if (link != nullptr)
    {
        //Item* before = prev;
        //Item* after = next;

        if (prev != nullptr)
        {
            prev->next = next;
        } else 
        {
            link->first = next;
        }

        if (next != nullptr)
        {
            next->prev = prev;
        } else
        {
            link->last = prev;
        }

        prev = nullptr;
        next = nullptr;
        link = nullptr;

    }
}

void List::insertFirst(Item* fresh)
{
    insert(nullptr, fresh, first);
}

void List::insertLast(Item* fresh)
{
    this->insert(this->last, fresh, nullptr);

}

void Item::insertAfter(Item* fresh)
{
    this->link->insert(this, fresh, this->next);

}

void Item::insertBefore(Item* fresh)
{
    link->insert(prev, fresh, this);
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
    cout << "End of the slist" << endl;
    cout << endl;
}

Item* List::find(string name0)
{
    Item* p = first;
    while (p != nullptr && p->name != name0)
    {
        p = p->next;
    }
    
    // p == nullptr || p->name == name0 ;

    return p;
}


int main()
{
    List a;

    a.print();

    a.insertFirst (new Item("red", 255, 0, 0));
    a.insertLast (new Item ("green", 0, 255, 0));
    
    a.first -> insertAfter (new Item("blue", 0, 0, 255));
    a.last -> insertBefore (new Item("yellow", 255, 255, 0));

    Item* t = a.find ("green");
    if (t == nullptr)
    {
        cout << "We didn't find" << endl;
    } else
    {
        cout << "We found " << t->r << " " << t->g << " " << t->b << endl;
        cout << endl;
        t->remove ();
        a.insertFirst (t);

    }

    a.print();

    List b;
    while (a.first != nullptr)
    {
        Item* t = a.first;
        t->remove();
        b.insertFirst(t);
    }

    a.print();
    b.print();


    cout << "O.K." << endl;
}

