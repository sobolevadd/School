// Soubor 15-00D.cpp
// Ukazka definice konverzniho operatoru
// Ve tride Y je definovan operator konverze na X a na int


#include <iostream>
using namespace std;

class Y {
	long i;
public:
	Y(int y):i(y){}
};

class X {
	int i;
public:
	X(int y):i(y){}
	operator Y(){ return Y(i); } 	// Pøetypování na Y
	operator int() { return i; } 	// Pøetypování na int
};

int main()
{
	Y a(0);
	X b(9);
	a = b;				// Pouzije se konverze X na Y
	cout << b << endl;		// Pouzije se konverze X na int
	return 0;
}
