#include <iostream>
//#include <stdlib.h>
//#include <string.h>
//#include <vector>

using namespace std;


int NactiNezaporne()
{
 	for(;;)
	{
		cout << "Zadej pros�m nez�porn� cel� ��slo: ";
		int n;
		cin >> n;
		if(!cin)
		{
			cout << "Zadan� vstup nep�edstavuje cel� ��slo."
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
			cout << "Zadan� vstup p�edstavuje z�porn� cel� ��slo."
				     " Zkuste to znovu." << endl;
			continue;
		}
	}
}

int NactiNezaporne1()
{
 	for(;;)
	{
		cout << "Zadej pros�m nez�porn� cel� ��slo: ";
		int n;
		cin >> n;
		if(!cin)
		{
			cout << "Zadan� vstup nep�edstavuje cel� ��slo."
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
			cout << "Zadan� vstup p�edstavuje z�porn� cel� ��slo."
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
	cout << "Faktori�l ��sla " << m << " je " << faktorial(m) << endl;
}