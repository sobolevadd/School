// Soubor 06-0A.CPP
// Priklad pouziti prikazu switch
// Podle toho, zda stisknete klavesdu 
// A, B, C, D nebo neco jineho (a pak Enter)
// vypise text

#include <iostream>
#include <cstdio>
using namespace std;

void Klavesa_A()
{
	cout << "stisknuta klavesa A" << endl;
}

void Klavesa_B()
{
	cout << "stisknuta klavesa B" << endl;
}

void Klavesa_C()
{
	cout << "stisknuta klavesa C" << endl;
}

void Klavesa_D()
{
	cout << "stisknuta klavesa D" << endl;
}

void NejakaJina()
{
	cout << "stisknuta nejaka jina klavesa " << endl;
}
int main()
{
	switch(int c = getchar())
	{
	case 'A':
		Klavesa_A(); break;
	case 'B':
		Klavesa_B(); break;
	case 'C':
		Klavesa_C(); break;
	case 'D':
		Klavesa_D(); break;
	default:
		NejakaJina(c); break;
	}

}