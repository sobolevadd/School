#include <iostream>
#include <stdlib.h>

using namespace std;



int A(int m, int n)
{
	static int PocetVolani = 0;
	cout << ++PocetVolani << ". volání funkce A s parametry m = " << m << ", n = " << n << endl;
	if(m == 0)
		return n + 1;
	else if(n == 0)
		return A(m-1, 1);
	else
		return A(m-1, A(m, n-1));
}

int main()
{
	system("CHCP 1250 > NUL");
	int j = A(1, 3);
	cout << "A(1, 3) = " << j << endl;
}