#include <iostream>

using namespace std;

void swap1(int& a, int& b){ //swap(x, y)
    int c = a;
    a = b;
    b =c;
};

void swap2(int&& a, int&& b){ //swap(x+1, y+1)
    int c = a;
    a = b;
    b =c;
};

int main(){
    int* p;
    p = new int(5); // p = new int{5};
    cout << *p << endl;
    delete p;

    int n;
    n = 8;
    p = new int[n] {1, 2, 3, 4, 5};
    //int A[n];
    for ( int i = 0; i < n+1; i++){
        cout << p[i] << ", ";
    }
    cout << endl;
    delete[] p;

    int(* q)[5] = new int[n][5] { {1,2,3,4,5,},{},{} };
    delete[] q;

    ////

    int& r = n;
    r = 98;
    p = &r;
    *p = 100;

    int x = 8, y =6;
    swap1(x, y);
    swap(x, y);

    int&& pr = 1 + x;
}

//(single/double) linked list - spojovy seznam