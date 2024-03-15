#include <iostream>
#include <locale>
using namespace std;

int main()
{
	union {
		short int i;
		unsigned char c[2];
	}; 
	wcout.imbue(locale("Czech_Czech Republic.852"));
	i = 0x1234;
	if (c[0] == 0x12)
	{
		wcout << "velký";
	}
	else
	{
		wcout << "malý";
	}
	wcout << endl;
}