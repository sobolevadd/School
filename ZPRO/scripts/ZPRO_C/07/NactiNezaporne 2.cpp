#include <iostream>
#include <stdlib.h>

using namespace std;


int NactiNezaporneCislo()
{
	int nacteno;
	do
	{
		cout << "Zadej nezáporné èíslo: ";
		cin >> nacteno;
	} while (nacteno < 0);
	return nacteno;
}



int NactiNezaporne()
{
 	for(;;)
	{
		cout << "Zadej prosím nezáporné celé èíslo: ";
		int n;
		cin >> n;
		if(!cin)
		{
			cout << "Zadaný vstup nepøedstavuje celé èíslo."
				    " Zkuste to znovu." << endl;
			cin.clear();
			char pom[100];
			cin >> pom;
			continue;
		}
		if(n >= 0)
		{
			return n;
		}
		else
		{
			cout << "Zadaný vstup pøedstavuje záporné celé èíslo."
				     " Zkuste to znovu." << endl;
			continue;
		}
	}
}

int NactiNezaporne1()
{
 	for(;;)
	{
		cout << "Zadej prosím nezáporné celé èíslo: ";
		int n;
		cin >> n;
		if(!cin)
		{
			cout << "Zadaný vstup nepøedstavuje celé èíslo."
				    " Zkuste to znovu." << endl;
			cin.clear();
			char pom[100];
			cin >> pom;
			goto Konec;
		}
		if(n >= 0)
		{
			return n;
		}
		else
		{
			cout << "Zadaný vstup pøedstavuje záporné celé èíslo."
				     " Zkuste to znovu." << endl;
			goto Konec;
		}
		Konec: ;
	}
}


int main()
{
	system("CHCP 1250 > NUL");
	cout << NactiNezaporneCislo() << endl;
}