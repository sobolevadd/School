/*using void
#include <iostream>

using namespace std;

void FullName (string fname = "Katya ", int age = 18) //fname - parametr
{  
    cout << fname << "Soboleva " << age << "years old\n";
};  

int main()
{
    FullName ("Daria ", 35); // "Daria" - argument
    FullName ("Natalia ", 28);
    FullName ();
    return 0;
}*/


#include <iostream>

using namespace std;

//ARRAY

struct Array
{
    double biggestElement; 
    int possitionOfBiggestElement = 0;
    double smallestElement;
    int possitionOfSmallestElement = 0;
    double addtionOfElements;
    double multiplicationOfElements;
};

void print(Array);
Array maxAndMinElement(const double[], const int);
Array AddtionAndMulOfElements(const double[], const int,Array);


int main()
{
    double x[] = {1.1, 2.2, 46, 33, -2,3};
    int lenght = sizeof(x)/sizeof(x[0]);
    Array myVector = maxAndMinElement(x,lenght);
    myVector = AddtionAndMulOfElements(x,lenght,myVector);
    print(myVector);
    return 0;
}

void print(Array vector)
{
    cout << "The biggest element in vector x is: " << vector.biggestElement << " the possition of the biggest element is: ";
    cout << vector.possitionOfBiggestElement << endl;
    cout << "The smallest element is: " << vector.smallestElement;
    cout << " and the possition of the smallest element is: " << vector.possitionOfSmallestElement << endl;
    cout << "The result of addtion of all elements in vector is: " << vector.addtionOfElements << endl;
    cout << "The result of multiplication of all elements in vector is: " << vector.multiplicationOfElements << endl;
}

Array maxAndMinElement(const double  x[], const int lenght)
{
    Array result;
    result.biggestElement = x[0];
    result.smallestElement = x[0];
    for (int i {0}; i < lenght; i++){
        if (x[i] > result.biggestElement){
            result.biggestElement = x[i]; 
            result.possitionOfBiggestElement = i;
        }else if (x[i] < result.smallestElement){
            result.smallestElement = x[i];
            result.possitionOfSmallestElement = i;
        }
    }
    return result;
}

Array AddtionAndMulOfElements(const double x[], const int lenght, Array result)
{
    result.addtionOfElements = 0;
    result.multiplicationOfElements = 1;
    for (size_t i {0}; i < lenght; i++){
        result.addtionOfElements += x[i];
        result.multiplicationOfElements *= x[i];
    }
    return result;
}

/* RECCURSIVE LOGHI
#include <iostream>

using namespace std;

enum {OK , ERROR_INPUT = 100,};

int factorial(int, int);

int main()
{
    int number {0};
    cout << "Enter positive int, max 12: ";
    cin >> number;
    if (number < 0 || number > 12){
        cout << "Wrong input!" << endl;
        return ERROR_INPUT;
    }
    int sum {1};
    sum = factorial(number, sum);
    cout << "The factorial of number " << number << " is: " << sum << endl;
    return OK;
}

int factorial(int number, int sum)
{
    if (number == 1 || number == 0){
        return sum;
    }else{
        sum *= number;
        number--;
        sum = factorial(number, sum);
        return sum;
    }
}
*/

/* RECCURSIVE ERRORS:))
#include <iostream>

using namespace std;

double fmax (double x[], int n);

int main()
[
    
    double x[] = {1.1,2.2,3.3};
    int n = sizeof(x)/sizeof(x[0]);
    double xmax = fmax (x,n);
    cout << "Nejvetsi prvek vektoru x je maxx = " << xmax << endl;
    return 0;
]


double fmax (double x[], int n)
{
    double maxx = x[0];
    for (int i = 1; i <= n - 1; i++)
    {
        if (x[i] > maxx)
        {
            maxx = x[i];
        }
    }
    return maxx;
}*/

/* idk
#include <iostream>

using namespace std;

int supf1(int n);

int main()
{
    int n;
    cout << "Enter n: " << endl;
    cin >> n;
    int f = supf1 (n);
    cout << " f = " << f << endl;
    return 0;
}

int supf1(int n)
{
    int f = 1;
    if ((n == 0)||(n = 1))
    {
        return f;
    }else
    {
        f = n * supf1(n - 1);
    }
    return f;
}*/