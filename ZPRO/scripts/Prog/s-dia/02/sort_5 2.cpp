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

using u_kompar�tor = bool(*)(wstring, wstring);
//typedef bool(*u_kompar�tor)(wstring, wstring);

wchar_t * text_n�pov�dy = LR"(
Filtr SORT
Pou�it�: SORT volba < vstupn�_soubor  > v�stupn�_soubor

volba            v�znam
-----------------------
-n nebo /n       �azen� podle ��sel
-l nebo /l       lexikografick� �azen�
-a nebo /a       abecedn� �azen�
)";


enum class typ{ dos, win };

string info_o_lok�lu(LCID lcid, int co)
{
	char text[128] = { 0 };
	GetLocaleInfoA(lcid, co, text, 127);
	return string(text);
}

string popis_lok�lu(typ kter�)
{
	LCID lcid = GetUserDefaultLCID();
	string popis = info_o_lok�lu(lcid, LOCALE_SENGLANGUAGE);
	if (popis.length() == 0)
	{
		return "C";
	}
	string pom = info_o_lok�lu(lcid, LOCALE_SENGCOUNTRY);
	if (pom.length() > 0)
	{
		popis += "_" + pom;
	}
	else
	{
		return popis;
	}
	int co = (kter� == typ::win) ? LOCALE_IDEFAULTANSICODEPAGE : LOCALE_IDEFAULTCODEPAGE;
	pom = info_o_lok�lu(lcid, co);
	if (pom.length() > 0)
	{
		popis += "." + pom;
	}
	return popis;
}

locale lok�l(popis_lok�lu(typ::win));

bool podle_��sel(wstring ��dka1, wstring ��dka2);


unordered_map<string, u_kompar�tor> tabulka_voleb = { { "-n", podle_��sel },
{ "-l", [](wstring �1, wstring �2)->bool {return �1 <= �2; } },
{ "-a", [](wstring �1, wstring �2)->bool {return lok�l(�1, �2); } },
};

void n�pov�da()
{
	wcerr.imbue(locale(popis_lok�lu(typ::dos)));
	wcerr << text_n�pov�dy << endl;
	exit(0);
}

void �azen�(u_kompar�tor komp)
{
	wstring ��dka;
	vector<wstring> vstup;

	wcout.imbue(lok�l);
	wcin.imbue(lok�l);

	while (getline(wcin, ��dka))
	{
		vstup.push_back(��dka);
	}
	sort(vstup.begin(), vstup.end(), komp);
	for (wstring lajna : vstup)
	{
		wcout << lajna << endl;
	}
}

bool podle_��sel(wstring ��dka1, wstring ��dka2)
{
	wistringstream A(��dka1), B(��dka2);
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
		�azen�(tabulka_voleb.at(argv[1]));
	}
	catch (out_of_range)
	{
		n�pov�da();
	}
}