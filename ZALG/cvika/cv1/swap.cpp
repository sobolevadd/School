#include <iostream>
using namespace std;

int x = 10;
int y = 20;

void swap_a (int * a, int * b)
{
    cout << "a = " << *a << ", b = " << *b << endl;
    int t = *a;
    *a = *b;
    *b = t;
    cout << "a = " << *a << ", b = " << *b << endl;
}

void swap_b (int & a, int & b)
{
    cout << "a = " << a << ", b = " << b << endl;
    int t = a;
    a = b;
    b = t;
    cout << "a = " << a << ", b = " << b << endl;
}

void unswap (int a, int b)
{
    cout << "a = " << a << ", b = " << b << endl;
    int t = a;
    a = b;
    b = t;
    cout << "a = " << a << ", b = " << b << endl;
}

int main()
{
   cout << "x = " << x << ", y = " << y <<endl;
   swap_b(x, y);
   cout << "x = " << x << ", y = " << y <<endl;
   unswap(x, y);
   cout << "x = " << x << ", y = " << y <<endl;
}