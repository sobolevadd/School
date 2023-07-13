#include <iostream>


using namespace std;

void print(string xdf);

int soucet (int a, int b)
{
    int c = a + b;
    string yyy = "Probiha soucet!";
    print(yyy);
    return c;
}

int main()
{
    string name = "Mac";
    print(name);
    int number1 = 20;
    int number2 = 30;
    int vysledek = 0;
    vysledek = soucet(number1, number2);
    cout << "Vysledek souctu je: " << vysledek << endl;
    
    
    string hobby;
    cout << "Co rad delas";
    getline (cin,hobby);
    
    string name = "Daria";
    int age = 20;
    cout << "Jake je tvoje jmeno? ";
    getline(cin, name);
    cout << "Kolik ti je? ";
    cin >> age;
    cout << "Ahoj " << name << " Je ti: " << age << endl;
    
    int i = 1;
    int imax = 10;
    int ans = 1;
    cout << "Zadej cislo " ;   
    cin >> imax ;
    cout << "asd"<< " afs" << endl;


    while (i<=imax)
    {

        ans = i*ans;

        cout << "i=" << i << endl;
        i++;
    }
    cout << "Ans: "<< ans << endl;



    int sum = 1;
    for (int i{2}; i <= 10; i++)
    {
        sum *= i; // sum = sum * i
    }
    cout << "Vysledek for cyklu je: " << sum << endl;

    
    return 0;
} 

void print(string xdf)
{
    cout << xdf << endl;
}

