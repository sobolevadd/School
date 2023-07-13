// Soubor 13-0B.CPP
//Nektera makra ze skripta a prostor pro experimenty

#include <iostream>
using namespace std;

#define PI 3.14159265358
#define MAK

#define MAX(a,b) ((a)>(b)?(a):(b))

#define CUBE(x) ((x)*(x)*(x))

#define SPOJ(i,j) i ## j

#define TISK(a) cout << #a << a << endl;

int x = 3;

int main()
{
	cout << CUBE(x+1) << endl;

	int i1 = 5, i2 = 33;
	cout << SPOJ(i,1) << ' ' << SPOJ(i,2) << endl;

	TISK(i1);

}