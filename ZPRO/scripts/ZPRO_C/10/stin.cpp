#include <iostream>
#include <stdlib.h>

using namespace std;



int main()
{
	system("CHCP 1250 > NUL");
	int i = 66;
	{
		cout << i << endl;
		int i = 77;
		cout << i << endl;
	}
	cout << i << endl;
}