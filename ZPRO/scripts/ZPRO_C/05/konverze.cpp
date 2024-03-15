#include <iostream>
#include <limits.h>
using namespace std;

int main()
{
	short k;
	int i;
	unsigned j;
	k = 700;
	i = k;
	cout << i << endl;
	j = k;
	cout << j << endl;
	k = -700;
	j = k;
	cout << j << endl;

}