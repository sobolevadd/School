#include <stdlib.h>
#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>



using namespace std;

const int N = 100;

int Faktorial(int n)
{
	if(n < 0) throw invalid_argument("záporný argument faktoriálu: ");
	int vysledek = 1;
	while(n)
	{
		vysledek *= n--;
	}
	return vysledek;
}

int BezpecneCteni(istream &proud)
{
    int n;
    proud >> n;                         // Zkus naèíst celoèíselnou hodnotu,
    if(!proud)                          // a když se to nepovede,
    {
        proud.clear();                  // resetuj proud, pøeèti do pomocné
        char pom[100];                  // promìnné, co uživatel zadal,
        proud >> pom;                   // zapomeò to a vyvolej výjimku,
        throw range_error("Vstup není èíslo");
    }                                   
    return n;                           // jinak vra pøeètenou hodnotu.
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
		catch(...)
		{
			cout << "Neznámá chyba. Informujte prosím dodavatele programu.";
		}
	}
}
