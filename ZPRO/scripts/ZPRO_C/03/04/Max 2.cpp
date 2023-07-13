#include <iostream>

using namespace std;

int Max(int a, int b)
{
	if(a>b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int x = 8, y = 9, z;
	z = max(x, y);
}