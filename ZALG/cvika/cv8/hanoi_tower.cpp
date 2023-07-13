#include <iostream>
#include <time.h>
#include <assert.h>
using namespace std;

enum {OK};

const int N = 5;


struct Tower
{
    int h; //height
    int p[N];
};

void init(Tower& X)
{
    X.h = 0;
    for (int i = 0; i < N; i++)X.p[i] = 0;
}

void setup(Tower& X)
{
    X.h = N;
    for (int i = 0; i < N; i++)X.p[i] = N - i;
    
}

void step(Tower& X, Tower& Y)
{
    assert(X.h > 0);
    int d = X.p[X.h - 1]; //d - disk
    X.h--;

    assert (Y.h < N);
    if (Y.h > 0)
    {
        assert (Y.p[Y.h - 1] > d );
    }
    
    Y.h++;
    Y.p[Y.h - 1] = d;
}

void print(Tower& X)
{
    for (int i = 0; i < N; i++)
    {
        if (i < X.h)
        {
            cout << X.p[i] << " ";
        } else 
        {
            cout << "  ";
        }
    }
}

Tower A, B, C;
void printTower()
{
    print(A);
    cout << " : " ;
    print(B);
    cout << " : " ;
    print(C);
    cout << endl;
}



int main ()
{
    return OK;
    setup(A);
    init(B);
    init(C);
    printTower();
    step (A, B);
    printTower();
    step (A, C);
    printTower();
    step (B, C);
    printTower();
}