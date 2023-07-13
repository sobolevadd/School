// Soubor 20-00D.cpp
// Vyjimky vyvolavane proudem: cteni v nekonecnem cyklu
// skonci vyjimkou

#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
void CtiCelaCisla(vector<int>& v, istream& F)
{
	ios_base::iostate old_st=F.exceptions();	// Ulo� p�vodn� stav
	F.exceptions(ios_base::eofbit);		// V�jimka p�i konci souboru
	try {
		for(;;)												// Nekone�n� cyklus
		{
			int i;
			F >> i;											// P�e�ti
			v.push_back(i);								// Ulo� do vektoru
		}
	}
	catch(ios_base::failure)
	{}																// Pr�zdn� handler
	F.exceptions(old_st);							// Obnov p�vodn� stav
}

int main()
{
	vector<int> v;
	CtiCelaCisla(v, ifstream("data.dta"));
	for(int i = 0; i < v.size(); i++)
		cout << v[i] << endl;
}