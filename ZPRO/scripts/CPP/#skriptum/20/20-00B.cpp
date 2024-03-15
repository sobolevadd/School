// Soubor 20-00B.cpp
// pouziti vstupniho proudu istringstream
// pro cteni s retezce a proudu ostringstream
// pro vytvoreni retezce

##include <iostream>
#include <sstream>
using namespace std;

// Pouziti vstupniho pametoveho proudu
// pri pocitani slov v retezci
int PocetSlov(string &s)
{
	int result = 0;
	istringstream Istr(s);			// Zkonstruujeme proud, kter�
	string w;						// bude pracovat s �et�zcem s
	while(Istr >> w) result++;		// �teme slova z proudu
	return result;
}

// Pouziti vystupniho pametoveho proudu 
// pro vytvoreni retezce
string Zprava(int n)
{
	ostringstream Zpr;
	Zpr << "Vas program, obsahuje " << n << " chyb";
	return Zpr.str();	// Ziskame retezec z proudu
}

int main()
{
  string sentence("Ko�ka leze d�rou, pes oknem");
  cout << PocetSlov(sentence) << endl
	  << Zprava(32) << endl;
}