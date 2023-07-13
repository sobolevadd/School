// Soubor 06-04.CPP
// Priklad pouziti prikazu continue 
// v cyklu
// vypise 01234013401234

#include <iostream>
using namespace std;
int main()
{
	for(int i=0; i<3; i++) 							// 1
	for(int j=0; j<5; j++) 						// 2
	{
		if((i==1)&&(j==2)) continue; 			// 3
		cout << j; 										// 4
	}
	return 0;
}
