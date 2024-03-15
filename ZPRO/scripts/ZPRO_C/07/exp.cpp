#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <math.h>

using namespace std;

double ENaMinusX1(double x, double eps)
{
	double suma = 1.0;         // Poèítaný souèet (na poèátku obsahuje nultý sèítanec)
	double scitanec = -x;      // Jednotlivý sèítanec (na ploèátku obsahuje první sèítavnc)
	int k = 1;                 // "Poèítadlo" (index sèítance v souètu, na poèátku 1)
    while(abs(scitanec) > eps)
	{
          scitanec = -x*scitanec/k++;        // Vypoèti další sèítanec a pøiprav se na další
          suma += scitanec;                  // pøièti ho k celkovému souètu
	}                          
     return suma;
}





int main()
{
	system("CHCP 1250 > NUL");
	cout << setprecision(10) << ENaMinusX1(-1, 1e-5) << endl;
	cout << ENaMinusX1(-1, 1e-5) - exp(1) << endl;
	cout << ENaMinusX1(100, 1e-5) << endl;
}