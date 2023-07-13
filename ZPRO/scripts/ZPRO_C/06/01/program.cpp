#include <iostream>
#include <stdlib.h>

#include "Kvadraticka.h"
using namespace std;


int main()
{
	system("CHCP 1250 > NUL");
	double rce[3] = {1,0,1};
	double x[2];
	reseni vysl = Res(rce, x);
	if(vysl == chyba)
	{
		cout << "Chybné zadání" << endl;
	}
	else if(vysl == realne)
	{
		cout << "x1 = " << x[0] << "; x2 = " << x[1] << endl;
	}
	else
	{
		cout << "x1,x2 = " << x[0] << " ± " << x[1] << ".i" << endl;
	}
}