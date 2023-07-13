#include <iostream>
using namespace std;

enum{OK};

class Item
{
public:
    int key = 0; //for now only key, later here could be useful values

    Item * left = nullptr;
    Item * right = nullptr;
};

Item * find (Item * top, int value)
{
    Item* result = nullptr;
    if (!top) //top == nulptr;
    {
        result = nullptr;
    } 
    else if (top->key == value)
    {
        result = top;
    }
    else if (top->key > value)
    {
        result = find(top->left, value);
    } 
    else
    {
        result = find (top->right, value);
    }
    return result;
}

Item * search (Item * top, int value)
{
    Item* p = top;

    while (p != nullptr && p->key != value)
    {
        if (value < p->key)
        {
            p = p->left;
        }
        else
        {
            p = p->right;
        }
        return p;
    }
}


Item* root = nullptr;

int main()
{
    Item* myRes = search (root, 20);
    find(root, 20);
    cout << (myRes ?  " Didn't find" : " Didn't find" ) << endl;
    return OK;
}
