// Soubor 12-03.CPP
// Priklad pouziti ukoncovacich
// funkci registrovanych pres atexit()

#include <cstdlib>
#include <iostream>
using namespace std;

void F1()
{
	cout << "Hl�s� se ukon�ovac� funkce F1" << endl;
}

void F2()
{
	cout << "Hl�s� se ukon�ovac� funkce F2" << endl;
}

int main()
{
	cout << "Hl�s� se hlavn� program" << endl;
	atexit(F1); 							// Registrace funkc� F1() a F2()
	atexit(F2);
	return 0;
}
