#include <iostream>
#include <stdlib.h>

using namespace std;


int main()
{
	int promenna = 8;
	__asm {                    // Vynuluje proměnnou
		XOR EAX, EAX
		mov promenna, EAX
	};
	cout << promenna << endl;
}