// Soubor 12-03.CPP
// Priklad pouziti ukoncovacich
// funkci registrovanych pres atexit()

#include <cstdlib>
#include <iostream>
using namespace std;

void F1()
{
	cout << "Hlásí se ukonèovací funkce F1" << endl;
}

void F2()
{
	cout << "Hlásí se ukonèovací funkce F2" << endl;
}

int main()
{
	cout << "Hlásí se hlavní program" << endl;
	atexit(F1); 							// Registrace funkcí F1() a F2()
	atexit(F2);
	return 0;
}
