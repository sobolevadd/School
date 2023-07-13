#include <iostream>

using namespace std;

void Zpracuj(int i)
{
	cout << i << endl;
}

void CtiKladna()
{
	int i;
	while(cin >> i, i > 0)
	{
		Zpracuj(i);
	}
}


int main()
{
	CtiKladna();
}