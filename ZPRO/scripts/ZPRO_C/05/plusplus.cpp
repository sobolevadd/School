#include <iostream>
#include <limits.h>
using namespace std;

int main()
{
	int i = INT_MAX;
	cout << i++ << endl;
	cout << i << endl;
	unsigned j = UINT_MAX;
    cout << j << endl;
	cout << ++j << endl;
}