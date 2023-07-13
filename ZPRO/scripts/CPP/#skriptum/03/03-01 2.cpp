// Soubor 03-01.CPP
// pokus o vymenu hodnot dvou promennych
// nefunguje, nebot parametry funkci swap()
// predavame hodnotou

#include <iostream>
using namespace std;
void swap(double a, double b)
{
	double c = a;
	a = b;
	b = c;
}

int main()	// Testovací program
{
	double d = 3.141592653589;
	double e = 2.7182818;
	cout 	<< "Pøed prohozením: " << endl
				<< "d = " << d << ", e = " << e << endl;
	swap(d, e);
	cout 	<< "Po prohození: " << endl
				<< "d = " << d << ", e = " << e << endl;
	return 0;
}
