#include <iostream>
#include <fstream>

#include <locale.h>
#include <iomanip>

using namespace std;

void Chyba(const char * jmeno)
{
	cerr << "nepodaøilo se otevøít soubor " << jmeno << endl;
}

using namespace std;

const int delka = 100;

void vypis(const char * jmeno)
{
	ofstream F(jmeno);
	if(F)
	{
		for(int i = 0; i < 10; i++)
		{
			F << setw(5) << i;
		}
		F.close();
	}
	else
	{
		Chyba(jmeno);
	}
}

void cteni(const char *jmeno)
{
	ifstream F(jmeno);
	if(F)
	{
		int i;
		while(F >> i)
		{
			cout << i << endl;
		}
		F.close();
	}
	else
	{
		Chyba(jmeno);
	}
}

int main()
{
	const char * jmeno = "data.txt";
	vypis(jmeno);
	cteni(jmeno);
}