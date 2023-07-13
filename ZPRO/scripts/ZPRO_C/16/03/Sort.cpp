#include <iostream>
#include "Seznam.h"

using namespace std;

int main()
{
	Seznam soubor;
	string lajna;
	while(getline(cin, lajna, '\n'))
	{
		lajna += '\n';
		soubor.vlozNakonec(lajna);
	}
	soubor.setrid(mensi); 
	soubor.vypis(cout);
}