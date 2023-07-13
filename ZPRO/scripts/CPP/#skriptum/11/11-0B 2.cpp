// Soubor 11-0B.CPP
// Priklad ruzne viditelnosti promennych

#include <iostream>
using namespace std;

char * Ia = "globální";						// Globální promìnná Ia

void Fun(char* Ia)	// Formální parametr Ia			
{
	cout << Ia << endl; 						// Vypíše formální parametr
	{
		char *Ia = "Vnoøená lokální";	// Lokální promìnná Ia
		cout << Ia << endl;					// Vypíše lokální promìnnou Ia
	}
	cout << Ia << endl;						// Vypíše formální parametr Ia
}

void Gun(void)
{
	cout << Ia << endl; 					// Vypíše globální promìnnou Ia
}

int main()
{ 
	Fun("parametr");
	Gun();
	return 0;
}
