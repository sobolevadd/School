#include <iostream>
#include "cplx.h"
using namespace std;

int main()
{
	using namespace knihovna;
	cplx z(1, 1);
	cplx w(3, 4);
	cplx t = w / z;
	cout << w.abs() << endl;
	z = 1;
	t = w + 1;
}