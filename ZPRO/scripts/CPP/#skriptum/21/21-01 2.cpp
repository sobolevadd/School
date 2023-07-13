// Soubor 21-01.cpp
// Implementace filtru SORT
// s p�ep�na�� -n (t��d�n� ��dk� podle �vodn�ch ��sel)
// a -c (t��d�n� ��dk� podle pravidel 
// �esk�ho abecedn�ho �azen�)
// P�elo�eno Visual C++ .NET jako aplikace pro Win32
// Pozor, p��padn� nefungov�n� je d�sledkem chyb 
// implementace STL, nikoli p�eklada�e
// 

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <locale>
using namespace std;

int PrikazovaRadka(char** argv)
{
	if((argv[1][0] != '/') && (argv[1][0] != '-' )) return 0;
	switch(argv[1][1])
	{
	case 'n': return 1;
	case 'c': return 2;
	default:  return 0;
	}
}


class PodleCisel
{
public:
	bool operator()(wstring& a, wstring &b);
};

bool PodleCisel::operator()(wstring& a, wstring &b)
{
	wistringstream A(a), B(b);
	int na=0, nb=0;
	A >> na;
	B >> nb;
	return na <= nb;
}

int main(int argc, char** argv)
{
	int prepinac = 0;
	locale lc("czech");
	wcin.imbue(lc);
	wcout.imbue(lc);
	if(argc > 1) prepinac = PrikazovaRadka(argv);
	wstring lajna;
	vector<wstring> soubor;
	// �ten� souboru
	while(getline(wcin, lajna)) soubor.push_back(lajna);
	// t��d�n� souboru
	switch(prepinac)
	{
	case 0:
		sort(soubor.begin(), soubor.end());
		break;
	case 1:
        sort(soubor.begin(), soubor.end(), PodleCisel());
	case 2:
		sort(soubor.begin(), soubor.end(), lc);
	}
	// V�stup souboru
	for(vector<wstring>::iterator i = soubor.begin();
		i != soubor.end(); ++i)
		wcout << *i << endl;
	return 0;
}