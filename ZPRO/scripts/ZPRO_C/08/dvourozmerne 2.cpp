#include <iostream>
#include <stdlib.h>

using namespace std;

int index(int n, int i, int j)
{
	return i * n + j;
}


int main()
{
	int m = 3, n = 4;
	system("CHCP 1250 > NUL");
	int *p = new int[n * m];
	for(int i = 0; i < m; i++)
	for(int j = 0; j < n; j++)
		p[index(n, i, j)] = 6;

	for(int i = 0; i < m*n; i++)
		cout << p[i] << endl;
	
}