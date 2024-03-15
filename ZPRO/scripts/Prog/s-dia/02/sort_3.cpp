#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdlib.h>
#include <locale>
#include <exception>
#include <sstream>
#include <unordered_map>

using namespace std;

using u_komparátor = bool(*)(wstring, wstring);
//typedef bool(*komparátor)(wstring, wstring);

wchar_t * text_nápovìdy = LR"(Filtr SORT
Použití: SORT [volba] < vstupní_soubor  > výstupní_soubor

volba            význam
-----------------------
-n nebo /n       øazení podle èísel
-l nebo /l       lexikografické øazení
)";

bool podle_èísel(wstring øádka1, wstring øádka2);
bool lexikograficky(wstring øádka1, wstring øádka2);

unordered_map<string, u_komparátor> tabulka_voleb({ { "-n", podle_èísel },
{ "/n", podle_èísel },
{ "-l", lexikograficky },
{ "/l", lexikograficky },
});

void nápovìda()//[[noreturn]]  // Ve VC++13 atribut noreturn nefunguje
{
	wcerr.imbue(locale("Czech_Czech Republic.852"));
	wcerr << text_nápovìdy << endl;
	exit(0);
}

void øazení(u_komparátor komp)
{
	wstring øádka;
	vector<wstring> vstup;

	while (getline(wcin, øádka))
	{
		vstup.push_back(øádka);
	}
	sort(vstup.begin(), vstup.end(), komp);
	for (wstring lajna : vstup)
	{
		wcout << lajna << endl;
	}
}


bool podle_èísel(wstring øádka1, wstring øádka2)
{
	wistringstream A(øádka1), B(øádka2);
	int nPrvni = 0, nDruhy = 0;
	A >> nPrvni;
	B >> nDruhy;
	return nPrvni <= nDruhy;
}

bool lexikograficky(wstring øádka1, wstring øádka2)
{
	return øádka1 <= øádka2;
}


int main(int argc, char** argv)
{
	try
	{
		if (argc != 2) throw out_of_range("");
		øazení(tabulka_voleb.at(argv[1]));
	}
	catch (out_of_range výjimka)
	{
		nápovìda();
	}
}