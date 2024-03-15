// Soubor 20-00A.cpp
// Pouziti vstupniho proudu v podmince
// cyklu pro cteni z textoveho souboru

#include <fstream>
#include <iostream>	// Kvùli proudu cout
using namespace std;
	
void chyba(){
	cerr << "nepovedlo se opevrit soubor" << endl;
}

void ctipis()
{ 
	ifstream F("data.dta");
 	if(!F) chyba();
 	int i;
 	while(F >> i)
 	{
		cout << i << endl;
 	}
}

int main()
{
	ctipis();
	return 0;
}
