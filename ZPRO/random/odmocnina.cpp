//napiste program na vypocet 3. odmocniny, s presnosti na 1; 0.1; 0.01; zadanou presnoti; puleni intervalu; newtonova metoda;


#include <iostream>
using namespace std;


int main ()
{
    int n;
    cout << "Zadej cislo ";
    cin >> n;
    int i = 1;
    while ((i*i*i)< n)
    {
       i++;

    }
    
    cout << " 3. odmocnina cisla = " << i << endl;

    double j= 0.1;
    while ( j*j*j < n)
    {
        j += 0.1;
    }
    cout <<  " 3. odmocnina cisla = " << j << endl;
    
    j = 0.01;
    while ( j*j*j < n)
    {
        j += 0.01;
    }
    cout <<  " 3. odmocnina cisla = " << j << endl;

    double k;
    double m;
    cout << "Zadej presnost ";
    cin >> m;
    while ( k*k*k < n)
    {
        k = k + m ;
    }
    cout <<  " 3. odmocnina cisla = " << k << endl;
    
    
    double l = 1;
    double m;
    cout << "Zadej presnost ";
    cin >> m;
    int p = 1;
    for (size_t i = 0; i < m; i++)
    {
       p /=  
    }
    
    while ( l*l*l < n)
    {
        l = l + m ;
    }
    cout <<  " 3. odmocnina cisla = " << l << endl;
}