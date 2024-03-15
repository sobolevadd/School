// Soubor 16-01A.cpp
// Vazba jmen
// pouzije se jmeno viditelne v miste deklarace
// sablony, nikoli jmeno viditelne v miste pouziti

#include <iostream>
	using namespace std;
int i = 64;
template<class T> T vratI() { return i; }

int main()
{
	int i = -32;
	cout << vratI<long>();	// Vypise 64
	return 0;
}
