#include <stdlib.h>
#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>



using namespace std;

const int N = 100;

int Faktorial(int n)
{
	if(n < 0) throw invalid_argument("z�porn� argument faktori�lu: ");
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
    proud >> n;                         // Zkus na��st celo��selnou hodnotu,
    if(!proud)                          // a kdy� se to nepovede,
    {
        proud.clear();                  // resetuj proud, p�e�ti do pomocn�
        char pom[100];                  // prom�nn�, co u�ivatel zadal,
        proud >> pom;                   // zapome� to a vyvolej v�jimku,
        throw range_error("Vstup nen� ��slo");
    }                                   
    return n;                           // jinak vra� p�e�tenou hodnotu.
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
		catch(...)
		{
			cout << "Nezn�m� chyba. Informujte pros�m dodavatele programu.";
		}
	}
}
