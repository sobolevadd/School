#include <iostream>

using namespace std;

void swapRef(int &a, int &b) // bez * se meni jenom lokalne, vysledek zustane x a y stejny
{
    int c = a;
    a = b;
    b = c;
}

void swapPtr(int *pa, int *pb) // ukazetele
{
    int c = *pa;
    *pa = *pb;
    *pb = c;
}

// zpusob praci s ukazatelemi kdyz pracujeme s dynamickemi promennemi, protoze muze byt neznamy vstup anebo protoze kapacita zasobniku je omezena


int main ()
{
    int x = 1, y = 2;
    cout << "Before swap x = " << x << ", y = " << y << endl;
    swapRef(x,y);
    swapPtr(&x, &y);
    cout << "After swap x = " << x << ", y = " << y << endl;
    return 0;
}