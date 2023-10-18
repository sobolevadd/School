#include <iostream>
#include "point.hpp"
//#include "point.cpp"

using namespace std;

enum{OK};

int main()
{
    Point a;
    Point b(1,1);

    Point *pc;

    b.print();
    pc = new Point(3,1);

    cout << "|ab| = " << a.distance(b) << endl;
    delete pc;
    pc = nullptr;
    cout << "|ab| = " << distance(a, b) << endl;

    print(a);
    a.print();
    return OK;
}