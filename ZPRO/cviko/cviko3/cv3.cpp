#include <iostream>

using namespace std;
/*using "func.hpp";

int main()
{
    double x[] = { 822.56, 9, 7, 87.8, -172, 1};
    int imax = 0;
    int lenght = sizeof(x)/sizeof(x[0]);
    arraymax(x, lenght);
    return 0;
}*/


/*
int main()
{
    double x[] = { 822.56, 9, 7, 87.8, -172, 1};
    int n = sizeof(x)/sizeof(x[0]);
    double S - x[0];
    for (int i = 1; i <- n-1; i++)
    {
        S = S + x[i];
    }
    cout << S;
}
*/


int main()
{
    double x[] = { 822.56, 9, 7, 87.8, -172, 1};
    double xmax = x[0];
    int imax = 0;
    int lenght = sizeof(x)/sizeof(x[0]);
    double res;
    
    for (int i = 1; i <= lenght; i++)
    {
        if (x[i] > xmax)
        {
            xmax = x[i];
            imax = i;
        }
    }
    cout << "Maximum is " << xmax << " on idx " << imax << endl;

    for (size_t i = 0; i < lenght; i++)
    {
        res += x[i];
    }
    cout << "The sum is: " << res << endl;


    return 0;
}


/*int main()
{
    int x[] = { 8, 9, 5, 7, 88, -172, 1};
    int xmax = x[0];
    int imax = 1;
    int lenght = sizeof(x)/sizeof(x[0]);
    for (int i = 1;i < lenght; i++)
    {
        if (x[i] > xmax)
        {
            xmax = x[i];
            imax = i;
        }
    }
    imax = imax + 1;
    cout << "Maximum is " << xmax << " je na " << imax << endl;

    return 0;
}

void flattering();

int main()
{
    flattering();
    return 0;
}

void flattering()
{
    string name;
    cout << "Enter your name: ";
    cin >> name;
    int age;
    cout << " Enter your age: ";
    cin >> age;
    if (age < 20)
    {
        cout << name << ", you re so young!" << endl;
    } else
    {
        cout << name << ", you re still very young!" << endl;
    }

}*/

