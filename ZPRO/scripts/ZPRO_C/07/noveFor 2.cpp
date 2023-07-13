#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>

using namespace std;



/*      // Nelze
void vypisPole(int X[])
{
	for(int i: X)
	{
		cout << X[i] << endl;
	}
}*/

void vypisVektor(vector<int> &v)
{
	for(int i : v)
		cout << i << " ";
}


int main()
{
	system("CHCP 1250 > NUL");

	int XX[10] = {1,2,4,7,4,6,8};
	
	vector<int> v(XX, XX+10);
	
	vypisVektor(v);
	for(int &i: XX)
	{
		i += 1;
	}
	for(int i: XX)
	{
		cout << i << " ";
	}
}