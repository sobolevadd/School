// Soubor 12-02.CPP
// Parametry funkce main()
// Program vypise parametry funkce main()
// a promenne operacniho systemu
// pozor, VYUZIVA NESTANDARDNI ROZSIRENI
// - TRETI PARAMETR FUNKCE main()

#include <iostream>
using namespace std;
void main(int argc, char *argv[], char *env[])
{
	cout 	<< "Program byl spu�t�n s " << argc 
				<< " parametry:" << endl;
	for(int i = 0; i < argc; i++) 
	{
		cout << argv[i] << endl;
	}
	cout << endl << "Prost�ed� opera�n�ho syst�mu:" << endl;
	i = 0;
	while(env[i])
		cout << env[i++] << endl;
}
