#include <iostream>
#include <stdlib.h>

using namespace std;


int NactiNezaporneCislo()
{
	int nacteno;
	do
	{
		cout << "Zadej nez�porn� ��slo: ";
		cin >> nacteno;
	} while (nacteno < 0);
	return nacteno;
}



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


int main()
{
	system("CHCP 1250 > NUL");
	cout << NactiNezaporneCislo() << endl;
}