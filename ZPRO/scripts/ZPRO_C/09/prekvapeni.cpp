#include <iostream>
#include <stdlib.h>
#include <limits.h>



using namespace std;



int main()
{
	system("CHCP 1250 > NUL");
	int i = INT_MAX;
	int j = 1;
	long long k = 0;
	
	cout << "i + j + k je   " << i + j + k << endl;
	cout << "i + (j + k) je " << i + (j + k) << endl;
	cout << "i + k + j je   " << i + k + j << endl;

	unsigned u = 0;
	int z = -1;
	cout << u << " + " << z << " je " << u + z << endl;
}