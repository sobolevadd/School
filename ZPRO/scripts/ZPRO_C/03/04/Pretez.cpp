#include <iostream>

using namespace std;

int max(int a, int b)
{
	return a > b ? a : b;
}

double max(double a, double b)
{
	return a > b ? a : b;
}

int main()
{
	int x = 8, y = 9, z;
	double xx = 8, yy = 7, zz;
	z = max(x, y);
	zz = max(xx, yy);
	//zz = max(x, xx);
}