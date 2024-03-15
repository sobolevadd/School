// Soubor 11-0A.CPP
// Priklad pouziti lokalni staticke promenne
// Promenna Pocet ve funkci f() slouzi jako pocitadlo
// volani

#include <iostream>
using namespace std;
void f()
{
	static int Pocet = 0;
	if(++Pocet == 100)
	{
		Pocet = 0;
		cout << "Další stovka..." << endl;
	}
	// ... a další pøíkazy tìla funkce f()
}
int main()
{ 
	for(int i = 0; i < 1000; i++) f();
 	return 0;
}
