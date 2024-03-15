#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdlib.h>
#include <locale>
#include <exception>
#include <sstream>

using namespace std;

typedef bool(*u_komparátor)(string, string);

void nápovìda()
{
	wcerr.imbue(locale("Czech_Czech Republic.852"));
	wcerr << L"Filtr SORT " << endl << L"Použití: SORT [volba] < vstupní_soubor  > výstupní_soubor" << endl;
	wcerr << L"volba:   -h /h -? /?  výpis nápovìdy" << endl;
	wcerr << L"         -n /n        øazení podle èísel " << endl;
	wcerr << L"         -l /l        lexikografické øazení" << endl;
	exit(0);
}

void øazení(u_komparátor komp)
{
	string øádka;
	vector<string> vstup;

	while (getline(cin, øádka))
	{
		vstup.push_back(øádka);
	}
	sort(vstup.begin(), vstup.end(), komp);
	for (string lajna : vstup)
	{
		cout << lajna << endl;
	}
}


bool podle_èísel(string øádka1, string øádka2)
{
	istringstream A(øádka1), B(øádka2);
	int nPrvni = 0, nDruhy = 0;
	A >> nPrvni;
	B >> nDruhy;
	return nPrvni <= nDruhy;
}

bool lexikograficky(string øádka1, string øádka2)
{
	return øádka1 <= øádka2;
}

u_komparátor zjisti_parametr(int argc, char** argv)
{
	if (argc != 2) nápovìda();
	if (argv[1][0] != '/' && argv[1][0] != '-')
		nápovìda();
	switch (argv[1][1])
	{
	default:
		nápovìda();
	case 'n':
		return podle_èísel;
	case 'l':
		return lexikograficky;
	}
}

int main(int argc, char** argv)
{
	øazení(zjisti_parametr(argc, argv));
}