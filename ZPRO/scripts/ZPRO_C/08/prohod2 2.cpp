#include <iostream>
#include <stdlib.h>

using namespace std;

void prohod(int &a, int &b)
{
	int c = a;
	a = b;
	b = c;
}

int main()
{
	system("CHCP 1250 > NUL");
	int x = 98, y = 89;
	cout << "Pùvodní hodnoty: " << x << " " << y << endl;
	prohod(x, y);
	cout << "Po funkci prohod: " << x << " " << y << endl;
}