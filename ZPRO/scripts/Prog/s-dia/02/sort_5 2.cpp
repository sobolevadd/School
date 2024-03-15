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

using u_komparátor = bool(*)(wstring, wstring);
//typedef bool(*u_komparátor)(wstring, wstring);

wchar_t * text_nápovìdy = LR"(
Filtr SORT
Použití: SORT volba < vstupní_soubor  > výstupní_soubor

volba            význam
-----------------------
-n nebo /n       øazení podle èísel
-l nebo /l       lexikografické øazení
-a nebo /a       abecední øazení
)";


enum class typ{ dos, win };

string info_o_lokálu(LCID lcid, int co)
{
	char text[128] = { 0 };
	GetLocaleInfoA(lcid, co, text, 127);
	return string(text);
}

string popis_lokálu(typ který)
{
	LCID lcid = GetUserDefaultLCID();
	string popis = info_o_lokálu(lcid, LOCALE_SENGLANGUAGE);
	if (popis.length() == 0)
	{
		return "C";
	}
	string pom = info_o_lokálu(lcid, LOCALE_SENGCOUNTRY);
	if (pom.length() > 0)
	{
		popis += "_" + pom;
	}
	else
	{
		return popis;
	}
	int co = (který == typ::win) ? LOCALE_IDEFAULTANSICODEPAGE : LOCALE_IDEFAULTCODEPAGE;
	pom = info_o_lokálu(lcid, co);
	if (pom.length() > 0)
	{
		popis += "." + pom;
	}
	return popis;
}

locale lokál(popis_lokálu(typ::win));

bool podle_èísel(wstring øádka1, wstring øádka2);


unordered_map<string, u_komparátor> tabulka_voleb = { { "-n", podle_èísel },
{ "-l", [](wstring ø1, wstring ø2)->bool {return ø1 <= ø2; } },
{ "-a", [](wstring ø1, wstring ø2)->bool {return lokál(ø1, ø2); } },
};

void nápovìda()
{
	wcerr.imbue(locale(popis_lokálu(typ::dos)));
	wcerr << text_nápovìdy << endl;
	exit(0);
}

void øazení(u_komparátor komp)
{
	wstring øádka;
	vector<wstring> vstup;

	wcout.imbue(lokál);
	wcin.imbue(lokál);

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


int main(int argc, char** argv)
{
	try
	{
		if (argc != 2) throw out_of_range("");
		if (argv[1][0] == '/')argv[1][0] = '-';
		øazení(tabulka_voleb.at(argv[1]));
	}
	catch (out_of_range)
	{
		nápovìda();
	}
}