// Soubor 20-00F.cpp
// Vlastni manipulator s parametrem
// !! Jen pro Visual C++ .NET !!


#include <iostream>
#include <iomanip>
using namespace std;

// Vlozi do proudu 10 prechodu na novy radek
void _linky(ios_base& os, int m)
{
	while (m--) dynamic_cast<ostream&>(os) << endl;
}

_Smanip<int> linky(int m)
{	
	return _Smanip<int> (_linky, m);
}


int main()
{
	cout << "ahoj" << linky(10) << "lidi" << endl;
}