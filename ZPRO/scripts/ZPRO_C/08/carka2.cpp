#include <iostream>

using namespace std;

const int n = 10;

void vypisPole(int * p, int n)
{
	for(int i = 0; i < n; i++)
		cout << p[i] << " ";
	cout << endl;
}

void otocPole(int * p, int n)
{
	for(int i = 0, j = n-1; i < j; i++, j--)
	{
		int a = p[i];
		p[i] = p[j];
		p[j] = a;
	}
}


int A[n] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};


int main()
{
	vypisPole(A, n);
	otocPole(A, n);
	vypisPole(A, n);
}