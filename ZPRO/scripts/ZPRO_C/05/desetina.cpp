// I kdy� ode��t�me opakovan� 0.1 od 1.0,
// x nikdy nebude 0, a to d�ky zaokrouhlovac�m chyb�m

#include <iostream>
using namespace std;

int main()
{
	double delta = 0.1;
	double x = 1;
	while (x != 0)
	{
		cout << x << endl;
		if(x < -2) return 0;
		x -= delta;
	}

}