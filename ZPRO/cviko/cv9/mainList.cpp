#include "list.cpp"

int main(){
    List *l = createList();
    pushFront(l, 12);
    pushFront(l, 14);
    popFront(l);
    pushFront(l, 10);
    pushFront(l, 2);
    //clean(l);
    pushFront(l, 42);
    remove(l, 10);
    pushBack(l,4);
    //destroyList(l);
    print(l);
    destroyList(l);
    //2 10 12
    return 0;
}