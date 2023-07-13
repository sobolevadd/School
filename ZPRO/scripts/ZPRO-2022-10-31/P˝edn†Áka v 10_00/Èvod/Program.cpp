#include <iostream>

using namespace std;

void prohod(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}

void prohod(int &&a, int &&b)
{

}

int main()
{
	// Dynamické promìnné
	int n;
	cout << "Zaèínáme" << endl;
	int* p = new int{ 5 };
	cout << *p << endl;
	delete p;
	n = 8;
	p = new int[n] {1, 2, 3, 4};
	for (int i = 0; i < 8; i++)
	{
		cout << p[i] << ", ";
	}
	cout << endl;
	delete[] p;
	int(* pp)[5];
	pp = new int[3][5]{ {1,2,3,4,5},{},{} };
	delete[] pp;
	// reference 

	int m = 9;
	int& r = m;
	r = 7;
	p = &r;

	int k = 99;
	prohod(m, k);
	int&& rr = m + 1;
}