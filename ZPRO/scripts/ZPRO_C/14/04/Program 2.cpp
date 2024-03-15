#include <stdlib.h>
#include <iostream>
#include "Bod.h"
#include "Usecka.h"

using namespace std;

const int N = 4;

int main()
{
	system("CHCP 1250 > NUL");
	GO *objekty[N];
	objekty[0] = new Bod(3, 5, 7);
	Bod A(5, 7, 9);
	Bod B(7, 7, 8);
	objekty[1] = new Usecka(5, A, B);
	objekty[2] = new Bod(1, 2, 6);
	objekty[3] = new Usecka(4, 6, 8, 2, 8);
	for (GO* p : objekty)
	{
		if(p)
			p -> Nakresli();
	}
	cout << endl << "blikání" << endl;
	objekty[0] ->Blikej ();
}