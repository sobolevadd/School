// Jen pro Visual C++
#include <stdlib.h>
#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>
#include <safeint.h>



using namespace std;
using namespace msl::utilities;

const int N = 100;

int Faktorial(int n)
{
	if(n < 0) throw invalid_argument("záporný argument faktoriálu: ");
	SafeInt<int> vysledek = 1;
	while(n)
	{
		vysledek *= n--;
	}
	return (int)vysledek;
}

long BezpecneCteni(istream & proud)
{
	char txt[N];
	cin >> txt;
	long vysledek;
	char * pom;
	vysledek = strtol(txt, &pom, 10);
	if(pom == txt)
		throw range_error("Vstup nepøedstavuje èíslo");
	return vysledek;
}


int main()
{
	system("CHCP 1250 > NUL");
	char txt[N];
	for(;;)
	{
		try {
			cout << "Zadej nezáporné celé èíslo: ";
			int n = BezpecneCteni(cin);
			cout << "Jeho faktoriál je " << Faktorial(n) << endl;
		}
		catch(range_error &e)
		{
			cerr << e.what() << endl;
			break;
		}
		catch(invalid_argument &e)
		{
			cout << "Faktoriál záporného èísla neexituje." << endl;
		}
		catch(SafeIntException &e)
		{
			cout << "Výsledek se nevejde do rozsahu typu int." << endl;
		}
		catch(...)
		{
			cout << "Neznámá chyba. Informujte prosím dodavatele programu." << endl;
		}
	}
}
