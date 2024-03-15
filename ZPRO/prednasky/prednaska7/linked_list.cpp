#include <iostream>
#include "list.hpp"

using namespace std;

int main(){
    list s1;
    CreateList(s1);
    Push_front(s1, 4);
    Push_front(s1, 5);
    Push_back(s1, 10);
    Pop_first(s1);
}