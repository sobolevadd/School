#include <iostream>

using namespace std;

int main()


{
    int number;
    int i = 2;
    string ans = "je prvocislo";
    cout <<"Zadej cele cislo ";
    cin >> number;

    while ( number > i){
        if (number % i == 0){
            ans = " neni prvocislo";
            break;
        }
        i++;
    }
    ans = " je provocislo";
    cout << "Cislo " << number << ans << endl;

}

#define prime 100
int main()

{ 
    int unsigned number = 2;
    string ans = " je prvocislo";
    cout << "Zadej cele cislo ";
    cin >> number;
    int i = 2;
    int prvocisla[prime] = {0};
    prvocisla[0] = 1;
    prvocisla[1] = 1;
    for (int i {2}; i < prime; i++)
    {
        if (prvocisla[i] == 1)
        {
            continue;
        }
        for (int j {2}; j < i; j++)
        {
            if (i % j == 0)
            {
                prvocisla[i] = 1;
                for (int k {2}; k * i < prime; k++)
                {
                    prvocisla[k*i] = 1;
                }
                break;
            }
            
        }
    }
    for (int l {0}; l < prime; l++)
    {
        if (prvocisla[l] == 0)
        {
            cout << l << " ";
        }
    }
    cout << endl;
    while (i<number)
    {
        if (number%i == 0)
        {
            ans = " neni prvocislo";
            break;
        }
        i++;
        
    }
    
    cout << "cislo " << number << ans << endl;
    
   
}