#include <iostream>
#include <stdlib.h>

using namespace std;

union JakTamJsou
{
	int cislo;
	char bajt[4];
};

int main()
{
	system("CHCP 1250 > NUL");
	JakTamJsou x = {0x12345678};
	cout << hex << (unsigned)x.bajt[0] << (unsigned)x.bajt[1] << (unsigned)x.bajt[2] << (unsigned)x.bajt[3] << endl;
	if(x.bajt[0] == 0x12)
	{
		cout << "Velký endián";
	}
	else
	{
		cout << "Malý endián";
	}
	cout << endl;
}