#include <iostream>
#include <string.h>
#include "Seznam.h"

using namespace std;

const char *pouceni =
	 "SORT -- program pro tøídìní souborù\n"
     "použití: SORT volba < vstup > výstup\n"
     "volba: -a  ... øazení dle ASCII\n"
     "       -n  ... øazení dle èísel na poèátku øádku "
     "implicitnì je nastaveno -a";

komparator zpracujParametryProgramu(int argc, char *argv[])
{
	if(argc == 1)
		return mensi;
	if(argc == 2)
	{
		if(strcmp(argv[1], "-a") == 0)
			return mensi;
		if(strcmp(argv[1], "-n") == 0)
			return mensiDleCisel;
	}
	cerr << pouceni << endl;
	return nullptr;
}

int main(int argc, char *argv[])
{
	system("CHCP 1250 > NUL");
	komparator jak = zpracujParametryProgramu(argc, argv);
	if(jak)
	{
		Seznam soubor;
		string lajna;
		while(getline(cin, lajna, '\n'))
		{
			lajna += '\n';
			soubor.vlozNakonec(lajna);
		}
		soubor.setrid(jak); 
		soubor.vypis(cout);
	}
}