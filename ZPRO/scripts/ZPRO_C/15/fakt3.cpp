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
	if(n < 0) throw invalid_argument("z�porn� argument faktori�lu: ");
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
		throw range_error("Vstup nep�edstavuje ��slo");
	return vysledek;
}


int main()
{
	system("CHCP 1250 > NUL");
	char txt[N];
	for(;;)
	{
		try {
			cout << "Zadej nez�porn� cel� ��slo: ";
			int n = BezpecneCteni(cin);
			cout << "Jeho faktori�l je " << Faktorial(n) << endl;
		}
		catch(range_error &e)
		{
			cerr << e.what() << endl;
			break;
		}
		catch(invalid_argument &e)
		{
			cout << "Faktori�l z�porn�ho ��sla neexituje." << endl;
		}
		catch(SafeIntException &e)
		{
			cout << "V�sledek se nevejde do rozsahu typu int." << endl;
		}
		catch(...)
		{
			cout << "Nezn�m� chyba. Informujte pros�m dodavatele programu." << endl;
		}
	}
}
