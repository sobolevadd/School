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

using u_kompar�tor = bool(*)(wstring, wstring);
//typedef bool(*kompar�tor)(wstring, wstring);

wchar_t * text_n�pov�dy = LR"(Filtr SORT
Pou�it�: SORT [volba] < vstupn�_soubor  > v�stupn�_soubor

volba            v�znam
-----------------------
-n nebo /n       �azen� podle ��sel
-l nebo /l       lexikografick� �azen�
)";

bool podle_��sel(wstring ��dka1, wstring ��dka2);
bool lexikograficky(wstring ��dka1, wstring ��dka2);

unordered_map<string, u_kompar�tor> tabulka_voleb({ { "-n", podle_��sel },
{ "/n", podle_��sel },
{ "-l", lexikograficky },
{ "/l", lexikograficky },
});

void n�pov�da()//[[noreturn]]  // Ve VC++13 atribut noreturn nefunguje
{
	wcerr.imbue(locale("Czech_Czech Republic.852"));
	wcerr << text_n�pov�dy << endl;
	exit(0);
}

void �azen�(u_kompar�tor komp)
{
	wstring ��dka;
	vector<wstring> vstup;

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

bool lexikograficky(wstring ��dka1, wstring ��dka2)
{
	return ��dka1 <= ��dka2;
}


int main(int argc, char** argv)
{
	try
	{
		if (argc != 2) throw out_of_range("");
		�azen�(tabulka_voleb.at(argv[1]));
	}
	catch (out_of_range v�jimka)
	{
		n�pov�da();
	}
}