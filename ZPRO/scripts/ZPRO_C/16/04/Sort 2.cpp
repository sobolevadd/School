#include <iostream>
#include <string.h>
#include "Seznam.h"

using namespace std;

const char *pouceni =
	 "SORT -- program pro t��d�n� soubor�\n"
     "pou�it�: SORT volba < vstup > v�stup\n"
     "volba: -a  ... �azen� dle ASCII\n"
     "       -n  ... �azen� dle ��sel na po��tku ��dku "
     "implicitn� je nastaveno -a";

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