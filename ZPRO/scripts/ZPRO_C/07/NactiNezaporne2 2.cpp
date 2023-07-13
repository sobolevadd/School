#include <iostream>
//#include <stdlib.h>
//#include <string.h>
//#include <vector>

using namespace std;


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


int faktorial(int n)
{
	int vysledek = 1;
	for(int i = 2; i <= n; i++)
		vysledek *= i;
	return vysledek;
}


int main()
{
	system("CHCP 1250 > NUL");
	int m = NactiNezaporne1();
	cout << "Faktoriál èísla " << m << " je " << faktorial(m) << endl;
}