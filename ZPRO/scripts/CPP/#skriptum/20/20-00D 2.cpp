// Soubor 20-00D.cpp
// Vyjimky vyvolavane proudem: cteni v nekonecnem cyklu
// skonci vyjimkou

#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
void CtiCelaCisla(vector<int>& v, istream& F)
{
	ios_base::iostate old_st=F.exceptions();	// Ulož pùvodní stav
	F.exceptions(ios_base::eofbit);		// Výjimka pøi konci souboru
	try {
		for(;;)												// Nekoneèný cyklus
		{
			int i;
			F >> i;											// Pøeèti
			v.push_back(i);								// Ulož do vektoru
		}
	}
	catch(ios_base::failure)
	{}																// Prázdný handler
	F.exceptions(old_st);							// Obnov pùvodní stav
}

int main()
{
	vector<int> v;
	CtiCelaCisla(v, ifstream("data.dta"));
	for(int i = 0; i < v.size(); i++)
		cout << v[i] << endl;
}