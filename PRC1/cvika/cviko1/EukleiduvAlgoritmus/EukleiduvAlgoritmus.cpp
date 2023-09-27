/*
Napiste program, ktery pro zadane cela cisla vypocita jejich nejmensi spolecny nasobek LCD
a nejvetsi spolecny delitel GCD

Bud a,b je z Z, a > b. Potom, dokud je b ruzne od nuly, opakuj nasledujici kroky:
    1. do m uloz zbytek po deleni a cislem b
    2. do a prirad b
    3. do b prirad m
Po skonceni algoritmu je v promenne a nejvetsi spolecny delitel GCD zadanych cisel.


Operator pro vypocet zbytku - %



#include <iostream>

using namespace std;

enum {OK};

int main ()
{
    int a, b, i;
    int gcd = 1, lcm = 1;
    cout << " Enter the two numbers you want to find the GCD and LCM of : " << endl;
    cin >> a >> b;
    for ( i = 1; i < 1000; i++)
    {
        if ((a % i == 0) && (b % i == 0))
        {
            gcd = i;          
        }
    }
    lcm = (a * b) / gcd;
    cout << " The GCD of the two numbers : " << a << " and " << b << " is : " << gcd << endl;
    cout << " The LCM of the two numbers : " << a << " and " << b << " is : " << lcm << endl;
    
    return OK;
}

*/

#include <iostream>

using namespace std;

enum {OK};

int gcd(int a, int b) {
    int m;
    while (b != 0){
        m = a % b; //do m uloz zbytek po deleni a cislem b
        a = b; //do a prirad b
        b = m; //do b prirad m
    }
    return a;
}

int main(){
    int x, y, g;
    cout << "Program to find the GCD of two numbers " << endl;
    cin >> x >> y;
    g = gcd(x, y);
    cout << "gcd(" << x << ", " << y << ") = " << g << endl;
    return OK;
}