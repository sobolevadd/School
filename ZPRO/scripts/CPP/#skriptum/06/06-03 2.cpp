// Soubor 06-03.CPP
// Priklad pouziti prikazu break 
// v cyklu
// vypise 012340101234

#include <iostream>
using namespace std;
int main()
{
	for(int i=0; i<3; i++) 							// 1
	for(int j=0; j<5; j++) 						// 2
	{
		if((i==1)&&(j==2)) break; 			// 3
		cout << j; 										// 4
	}
	return 0;
}
