// Soubor 09-02.CPP
// Pøíklad použití unie
//ke zjištìní zpùsobu ukládání celých èísel v pamìti

#include <iostream>
using namespace std;
union 
{
	long int i;
	unsigned char c[4];
} u;
int main()
{
 	u.i = 0x12345678L;
 	cout << hex << endl; 				// Výpis v šestnáctkové soustavì
 	for (int i = 0; i < 4; i++)
 		cout << (unsigned)u.c[i] << ' ';
 	return 0;
}
