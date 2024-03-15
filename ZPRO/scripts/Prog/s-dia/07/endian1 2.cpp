#include <iostream>
#include <locale>
using namespace std;

union {
	short int i;
	unsigned char c[2];
} u;

int main()
{
	wcout.imbue(locale("Czech_Czech Republic.852"));
	u.i = 0x1234;
	if (u.c[0] == 0x12)
	{
		wcout << "velký";
	}
	else
	{
		wcout << "malý";
	}
	wcout << endl;
}