#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <math.h>

using namespace std;

double ENaMinusX1(double x, double eps)
{
	double suma = 1.0;         // Po��tan� sou�et (na po��tku obsahuje nult� s��tanec)
	double scitanec = -x;      // Jednotliv� s��tanec (na plo��tku obsahuje prvn� s��tavnc)
	int k = 1;                 // "Po��tadlo" (index s��tance v sou�tu, na po��tku 1)
    while(abs(scitanec) > eps)
	{
          scitanec = -x*scitanec/k++;        // Vypo�ti dal�� s��tanec a p�iprav se na dal��
          suma += scitanec;                  // p�i�ti ho k celkov�mu sou�tu
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