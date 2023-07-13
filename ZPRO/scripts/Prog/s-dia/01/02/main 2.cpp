#include <iostream>
#include "cplx.h"
using namespace std;

int main()
{
	using namespace knihovna;
	cplx z(1, 1);
	cplx w(3, 4);
	cplx t = w / z;
	cout << abs(w) << endl;
	z = 1;
	cout << z << endl;
	t = w + 1;
	cin >> t;
	cout << t << endl;
	z = 1 + t;
	cout << z << endl;
}