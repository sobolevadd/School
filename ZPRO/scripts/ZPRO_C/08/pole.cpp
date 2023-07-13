#include <iostream>
#include <stdlib.h>

using namespace std;


int main()
{
	system("CHCP 1250 > NUL");
	
	cout << "Zadej, kolik prvkù nude pole mít: ";
	int n;
	cin >> n;
	int * aa = new int[n];
	for(int i = 0; i < n; i++)
		aa[i] = 0;

       // nìjaké použití
       delete[] aa;
}