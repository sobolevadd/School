#include <stdlib.h>
#include <iostream>

using namespace std;

#define SQR(x) x*x

#define SQR1(x) ((x)*(x))

int main()
{
	int x = 5;
	double y = 11.1;
	cout << SQR(x) << endl;
	cout << SQR(y) << endl;
	cout << SQR(x+1) << endl;
	cout << SQR1(x+1) << endl;
	cout << SQR1(x++) << endl;
}