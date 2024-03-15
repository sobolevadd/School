#include <iostream>
#include <cmath>
using namespace std;

float mocnina(float a, int b)
{
    if (b == 0)
    {
        return 1;
    } else if (b > 0)
    {
        int i = 1;
        float res = 1;
        while ( i <= b)
        {
            res = a*res;
            i++;
        }
        return res;
    } else
    {
        int i = 1;
        float res = 1;
        while ( i <= -b)
        {
            res = res/a;
            i++;
        }
        return res;
    }
    
    
    
}

int main () {

    int n;
    cout << "Zadej cislo " << endl;
    cin >> n;
    cout << "Zadej mocninu " << endl;
    int pow;
    cin >> pow;
    float moc = mocnina(n, pow);
    cout << "mocnina cisla " << n << " se rovna " << moc << endl; 

}

/*

const float PI = 3.14159;

float povrchKoule (float r) {
    float vysledek = 4* PI*pow(r, 2);
    return vysledek;
}

float objemKoule (float r) {
    return 4.0/3.0*PI*pow(r, 3);
}

int main () {}

    int n;
    cout << "Zadej cislo " << endl;
    cin >> n;
    cout << "2. mocnina cisla " << n << " se rovna " << n*n << endl; 

}


const float PI = 3.14159;

int max (int a, int b) {
    if (a < b){
        return b;
    }else if (a == b){
        cout << "Jsou stejne" << endl;
    }
    return a;
    
}

int main ()
{
    int number = max (-49, -49);
    cout << number << endl;
    //cout << max (-49, -45) << endl;
    
    float x = 0.0;
    while (abs (x-1.0) > 0.0001) {
        cout << x << endl;
        x = x + 0.1;
    }

    float x = 0.0;
    while (x != 1.0) {
        cout << x << endl;
        x = x + 0.1;
    }



    int i = 1;
    while (i <= 10) {
        cout << i << endl;
        i++;
    }
    


    float r; //polomer koule
    float s, v; //povrh a objem koule
    cout << "Program pro vypocet objemu a povrhu koule" << endl;
    cout << "Zadejte polomer koule [m]: ";
    cin >> r;
    if (r >= 0)
    {
        //s = 4* PI*r*r;
        s = 4* PI*pow(r, 2);
        //v = 4.0/3*PI*r*r*r;
        v = 4.0/3.0*PI*pow(r, 3);
        cout << "Povrh koule je " << s << "m2\n";
        cout << "Objem koule je " << v << "m3\n";
    }
    else
    {
        cout << "Polomer musi byt kladny\n";
        return 1;
    }
    
    return 0;
*/





