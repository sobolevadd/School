#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdlib.h>
#include <locale>
#include <exception>
#include <sstream>
#include <unordered_map>
#include <locale>

using namespace std;

using u_komparator = bool(*)(wstring, wstring);
//typedef bool(*u_komparator)(wstring, wstring);

wchar_t * text_napovedy = LR"(Filtr SORT
Pouziti: SORT [volba] < vstupni_soubor  > vystupni_soubor

volba            vyznam
-----------------------
-n nebo /n       razeni podle cisel
-l nebo /l       lexikograficke razeni
-a nebo /a       abecedni razeni
)";

locale lokal("Czech");

bool podle_cisel(wstring radka1, wstring radka2);
bool lexikograficky(wstring radka1, wstring radka2);
bool abecedne(wstring radka1, wstring radka2);

unordered_map<string, u_komparator> tabulka_voleb = { { "-n", podle_cisel },
{ "/n", podle_cisel },
{ "-l", lexikograficky },
{ "/l", lexikograficky },
{ "-a", abecedne },
{ "/a", abecedne },
};

void napoveda()
{
	wcerr.imbue(locale("Czech_Czech Republic.852"));
	wcerr << text_napovedy << endl;
	exit(0);
}

void razeni(u_komparator komp)
{
	wstring radka;
	vector<wstring> vstup;

	wcout.imbue(lokal);
	wcin.imbue(lokal);

	while (getline(wcin, radka))
	{
		vstup.push_back(radka);
	}
	sort(vstup.begin(), vstup.end(), komp);
	for (wstring lajna : vstup)
	{
		wcout << lajna << endl;
	}
}

bool abecedne(wstring radka1, wstring radka2)
{
	return lokal(radka1, radka2);
}

bool podle_cisel(wstring radka1, wstring radka2)
{
	wistringstream A(radka1), B(radka2);
	int nPrvni = 0, nDruhy = 0;
	A >> nPrvni;
	B >> nDruhy;
	return nPrvni <= nDruhy;
}

bool lexikograficky(wstring radka1, wstring radka2)
{
	return radka1 <= radka2;
}


int main(int argc, char** argv)
{
	try
	{
		if (argc != 2) throw out_of_range("");
		razeni(tabulka_voleb.at(argv[1]));
	}
	catch (out_of_range)
	{
		napoveda();
	}
}