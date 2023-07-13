#include <iostream>
using namespace std;

void triangle(int height);
void triangle2(int height);

int main()
{
    triangle(5);
    return 0;
}

void triangle(int height)
{
    for (int i {1}; i < height; i++){
        for (int j{0}; j < i; j++){
            cout << "* ";
        }
        cout << endl;
    }
    triangle2(height);
}

void triangle2(int height)
{
    cout << endl;
    for (int i {height}; i > 0; i--){
        for (int j{0}; j < i; j++){
            cout << "* ";
        }
        cout << endl;
    }
}