#include <iostream>
using namespace std;

int main()
{
	int i = 876;
	bool pokracovat = (i > 0) && (i < 1000);
	cout << pokracovat<< endl;
	cout << boolalpha << pokracovat << endl << noboolalpha;
	cout << pokracovat<< endl;
}