#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdlib.h>
#include <locale>
#include <exception>
#include <sstream>

using namespace std;

typedef bool(*u_kompar�tor)(string, string);

void n�pov�da()
{
	wcerr.imbue(locale("Czech_Czech Republic.852"));
	wcerr << L"Filtr SORT " << endl << L"Pou�it�: SORT [volba] < vstupn�_soubor  > v�stupn�_soubor" << endl;
	wcerr << L"volba:   -h /h -? /?  v�pis n�pov�dy" << endl;
	wcerr << L"         -n /n        �azen� podle ��sel " << endl;
	wcerr << L"         -l /l        lexikografick� �azen�" << endl;
	exit(0);
}

void �azen�(u_kompar�tor komp)
{
	string ��dka;
	vector<string> vstup;

	while (getline(cin, ��dka))
	{
		vstup.push_back(��dka);
	}
	sort(vstup.begin(), vstup.end(), komp);
	for (string lajna : vstup)
	{
		cout << lajna << endl;
	}
}


bool podle_��sel(string ��dka1, string ��dka2)
{
	istringstream A(��dka1), B(��dka2);
	int nPrvni = 0, nDruhy = 0;
	A >> nPrvni;
	B >> nDruhy;
	return nPrvni <= nDruhy;
}

bool lexikograficky(string ��dka1, string ��dka2)
{
	return ��dka1 <= ��dka2;
}

u_kompar�tor zjisti_parametr(int argc, char** argv)
{
	if (argc != 2) n�pov�da();
	if (argv[1][0] != '/' && argv[1][0] != '-')
		n�pov�da();
	switch (argv[1][1])
	{
	default:
		n�pov�da();
	case 'n':
		return podle_��sel;
	case 'l':
		return lexikograficky;
	}
}

int main(int argc, char** argv)
{
	�azen�(zjisti_parametr(argc, argv));
}