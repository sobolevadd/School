#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdlib.h>
#include <locale>
#include <exception>
#include <sstream>

using namespace std;

typedef bool(*u_komparator)(string, string);

void napoveda()
{
	wcerr.imbue(locale("Czech_Czech Republic.852"));
	wcerr << L"Filtr SORT " << endl << L"Pouziti: SORT [volba] < vstupni_soubor  > vystupni_soubor" << endl;
	wcerr << L"volba:   -h /h -? /?  vypis nápovedy" << endl;
	wcerr << L"         -n /n        razeni podle cisel " << endl;
	wcerr << L"         -l /l        lexikograficke razeni" << endl;
	exit(0);
}

void razeni(u_komparator komp)
{
	string radka;
	vector<string> vstup;

	while (getline(cin, radka))
	{
		vstup.push_back(radka);
	}
	sort(vstup.begin(), vstup.end(), komp);
	for (string lajna : vstup)
	{
		cout << lajna << endl;
	}
}


bool podle_cisel(string radka1, string radka2)
{
	istringstream A(radka1), B(radka2);
	int nPrvni = 0, nDruhy = 0;
	A >> nPrvni;
	B >> nDruhy;
	return nPrvni <= nDruhy;
}

bool lexikograficky(string radka1, string radka2)
{
	return radka1 <= radka2;
}

u_komparator zjisti_parametr(int argc, char** argv)
{
	if (argc != 2) napoveda();
	if (argv[1][0] != '/' && argv[1][0] != '-')
		napoveda();
	switch (argv[1][1])
	{
	default:
		napoveda();
	case 'n':
		return podle_cisel;
	case 'l':
		return lexikograficky;
	}
}

int main(int argc, char** argv)
{
	razeni(zjisti_parametr(argc, argv));
}