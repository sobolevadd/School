// Soubor 03-02.CPP
// Vymena hodnot dvou promennych
// Funguje -- parametry funkce swap()
// se predavaji ukazatelem
// lze pouzit v C i v C++

#include <iostream>
using namespace std;
void swap(double *a, double *b)
{
	double c = *a;
	*a = *b;
	*b = c;
}
int main()						// Testovac� program
{
	double d = 3.141592653589;
	double e = 2.7182818;
	cout 	<< "P�ed prohozen�m: " << endl
				<< "d = " << d << ", e = " << e << endl;
	swap(&d, &e);
	cout 	<< "Po prohozen�: " << endl
				<< "d = " << d << ", e = " << e << endl;
	return 0;
}
