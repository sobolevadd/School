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
#include <windows.h>

using namespace std;

using u_komparator = bool(*)(wstring, wstring);
//typedef bool(*u_komparator)(wstring, wstring);

wchar_t * text_napovedy = LR"(
Filtr SORT
Pouziti: SORT volba < vstupni_soubor  > vystupni_soubor

volba            vyznam
-----------------------
-n nebo /n       razeni podle cisel
-l nebo /l       lexikograficke razeni
-a nebo /a       abecedni razeni
)";


enum class typ{ dos, win };

string info_o_lokalu(LCID lcid, int co)
{
	char text[128] = { 0 };
	GetLocaleInfoA(lcid, co, text, 127);
	return string(text);
}

string popis_lokalu(typ ktery)
{
	LCID lcid = GetUserDefaultLCID();
	string popis = info_o_lokalu(lcid, LOCALE_SENGLANGUAGE);
	if (popis.length() == 0)
	{
		return "C";
	}
	string pom = info_o_lokalu(lcid, LOCALE_SENGCOUNTRY);
	if (pom.length() > 0)
	{
		popis += "_" + pom;
	}
	else
	{
		return popis;
	}
	int co = (ktery == typ::win) ? LOCALE_IDEFAULTANSICODEPAGE : LOCALE_IDEFAULTCODEPAGE;
	pom = info_o_lokalu(lcid, co);
	if (pom.length() > 0)
	{
		popis += "." + pom;
	}
	return popis;
}

locale lokal(popis_lokalu(typ::win));

bool podle_cisel(wstring radka1, wstring radka2);


unordered_map<string, u_komparator> tabulka_voleb = { { "-n", podle_cisel },
{ "-l", [](wstring r1, wstring r2)->bool {return r1 <= r2; } },
{ "-a", [](wstring r1, wstring r2)->bool {return lokal(r1, r2); } },
};

void napoveda()
{
	wcerr.imbue(locale(popis_lokalu(typ::dos)));
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

bool podle_cisel(wstring radka1, wstring radka2)
{
	wistringstream A(radka1), B(radka2);
	int nPrvni = 0, nDruhy = 0;
	A >> nPrvni;
	B >> nDruhy;
	return nPrvni <= nDruhy;
}


int main(int argc, char** argv)
{
	try
	{
		if (argc != 2) throw out_of_range("");
		if (argv[1][0] == '/')argv[1][0] = '-';
		razeni(tabulka_voleb.at(argv[1]));
	}
	catch (out_of_range)
	{
		napoveda();
	}
}