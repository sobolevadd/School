#include <iostream>
#include "stack.h"

using namespace std;

int main ()
{
    const int N = 8; // the maximum lenght of int hex number is 8
    int input;
    cout << "Please enter whole number: ";
    cin >> input;
    Stack *s;
    create(s, N);
    convertToHex(s, input);

    print(s);
    cout << "Control with hex function: " << hex << input << endl;
    destroy(s);
    return 0;
}