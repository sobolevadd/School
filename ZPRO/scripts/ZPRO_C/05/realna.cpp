#include <iostream>
#include <locale>
#include <iomanip>

using namespace std;

int main()
{
	double x = 3.14159265358979323;
	cout << x << endl << setprecision(3) << x << endl;

}