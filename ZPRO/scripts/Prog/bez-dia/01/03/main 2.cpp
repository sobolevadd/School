#include <iostream>
#include "cplx.h"
using namespace std;
using namespace knihovna;

using complex = cplx<double>;

// Znamena totez co naásledujici typedef
//typedef knihovna::cplx<double> complex;

//template knihovna::cplx<double>;

int main()
{
	complex z(1, 1);
	complex w(3, 4);
	complex t = w / z;
	double x = abs<double>(w);
	cout << abs(w) << endl;
	z = 1;
	cout << z << endl;
	t = w + z;
	cin >> t;
	cout << t << endl;
	z = w + (complex)1;
	cout << z << endl;
	z = knihovna::operator+<double>(w, 1.0);
}