// Soubor 11-0B.CPP
// Priklad ruzne viditelnosti promennych

#include <iostream>
using namespace std;

char * Ia = "glob�ln�";						// Glob�ln� prom�nn� Ia

void Fun(char* Ia)	// Form�ln� parametr Ia			
{
	cout << Ia << endl; 						// Vyp�e form�ln� parametr
	{
		char *Ia = "Vno�en� lok�ln�";	// Lok�ln� prom�nn� Ia
		cout << Ia << endl;					// Vyp�e lok�ln� prom�nnou Ia
	}
	cout << Ia << endl;						// Vyp�e form�ln� parametr Ia
}

void Gun(void)
{
	cout << Ia << endl; 					// Vyp�e glob�ln� prom�nnou Ia
}

int main()
{ 
	Fun("parametr");
	Gun();
	return 0;
}
