#include <iostream>
#include <math.h>

using namespace std;

enum struct Druh{ Realne, Komplexni};
enum { a, b, c };

struct Vysledek
{
    Druh druh;
    double vysledek[2];
};

Vysledek ResKvadratickouRovnici(double koef[1])
{
    double d = koef[b] * koef[b] - 4 * koef[a] * koef[c];
    Vysledek vysledek;
    if ( d >= 0)
    {
        d = sqrt(d);
        vysledek.druh = Druh::Realne;
        vysledek.vysledek[0] = (-koef[b] + d)/ 2 * koef[a];
        vysledek.vysledek[1] = (-koef[b] - d)/ 2 * koef[a];
    }else
    {
         d = sqrt(-d);
        vysledek.druh = Druh::Komplexni;
        vysledek.vysledek[0] = -koef[b] / 2 * koef[a];
        vysledek.vysledek[1] = d /2 * koef[a];
    }
    return vysledek;
}

int main()
{
    double koef[] = { 761, 27, 19 };
    Vysledek vysledek = ResKvadratickouRovnici(koef);
    if (vysledek.druh == Druh::Realne)
    {
        cout << "x1 = "<< vysledek.vysledek[0] << ", x2 = " << vysledek.vysledek[1] << endl;
    }else 
    {
        cout << "x1,2 = " << vysledek.vysledek[0] << "+- i*" << vysledek.vysledek[1] << endl; 
    }
}

/* STRUKTURA
struct Date
{
    int day;
    int month;
    int year;
};

int main()
{
    Date today { 10, 10, 2022 };
    today.day = 10;
}
*/

/* KVADRATICKA ROVNICE
#include <iostream>
#include <math.h>

using namespace std;

//Deskrimnant

enum DruhReseni { Realne, Komplexni };

enum{a, b, c}; //indexy koeficientu

DruhReseni ResKvadratickouRovnici(double koef[], double vysledek[] )
{
    double d = koef[b]*koef[b]-4*koef[a]*koef[c];
    if (d >= 0)
    {
        d = sqrt(d);
        vysledek[0] = (-koef[b] + d/ (2 * koef[a]));
        vysledek[1] = (-koef[b] - d/ (2 * koef[a]));
        return Realne;
    }else
    {
        d = sqrt(-d);
        vysledek[0] = -koef[b] / 2 * koef[a];
        vysledek[1] = d] / 2 / koef[a];
        return Komplexni;
    }
}

int main()
{
    double koeficienty[] = { 1, 2, 1 };
    double vysledek[2]{};
    DruhReseni druh = ResKvadratickouRovnici(koeficienty, vysledek);
    if (druh == Realne)
    {
        cout << "x1 = " << vysledek[0] << ", x2 = " << vysledek[1] << endl;
    }else 
    {
        cout << "x1,2 = " << vysledek[0] << "+- i*" << vysledek[1] << endl; 
    }
}
*/

/*
#include <iostream>
using namespace std;

int A[5] = {1,2,3,4,5,};

void f(int a)
{
    a = 9;
}

void ff(int A[])
{
    A[1] = 999;
}

int main()
{
    ff(A);
    //int b = 88;
    //f(b);
    A[1] = 9;
    int B[5];
    B[0] = 8;
    cout << A[5] << endl;
    int i = 0;
    while (i < 5)
    {
        B[i] = A[i];
        i++;
    }
}
*/

/*
#include <iostream>
#include <math.h>
#include <limits.h>

using namespace std;


int f(int i)
{
    cout << i << endl;
    return i + 1;
} 

int main()
{
    int i = INT_MIN;
    //cout << abs(i) << endl;
    unsigned u = UINT_MAX;
    cout << u << endl;
    cout << ++u << endl;
    (void) f(i);
    return 0;
}
*/

/*
#include <iostream>

using namespace std;

enum day {Monday, Tuesday, Wendsday, Thursday, Friday, Saturday, Sunday};
enum card{ Seven = 7, Eight, Nine, Ten};
//enum pokus {Seven, Monday}; // Nelze

enum class ZpusobOtevreni {Cteni, Zapis, CteniZapis};
enum class Opravneni {Cteni, Zapis, Spusteni};

int main()
{
    day today = Monday;
    //today = Seven;
    cout << today << endl;
    cout << Ten << " " << (day)Seven << endl;
    ZpusobOtevreni zo = ZpusobOtevreni::Cteni;
    cout << (int)zo << endl;
    return 0;
} */