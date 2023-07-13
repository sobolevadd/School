#include "list.hpp"

void CreateList(list& s){
    s.head = s.sentinel = new element {NULA, nullptr };
    s.length = 0;
}

void Push_front(list& s, T what){
    s.head = new element{what, s.head};
    s.length ++;
}

void Push_back(list& s, T what){
    s.sentinel-> data = what;
    s.sentinel -> next = new element{ what, nullptr};
    s.sentinel = s.sentinel -> next;
    s.length ++;
}

void Pop_first(list& s ){
    auto tmp = s.head;
    s.head = s.head -> next;
    delete tmp;
    s.length --;
}