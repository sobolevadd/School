// Soubor 20-00E.cpp
// Vlastni manipulator bez parametru

#include <iostream>
using namespace std;

// Vlozi do proudu 10 mezer
ostream& mez10(ostream& Ostr)
{ 
	return Ostr << "          ";
}


int main()
{
	cout << "ahoj" << mez10 << "lidi" << endl;
}