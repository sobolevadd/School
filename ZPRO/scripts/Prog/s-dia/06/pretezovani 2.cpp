#include <iostream>
#include <utility>

using namespace std;

int prom = 6;

void f(int&& i)
{
	cout << "odkaz na r-hodnotu" << endl;
}

void f(int &i)
{
	cout << "odkaz na l-hodnotu" << endl;
}

void f(const int& i)
{
	cout << "odkaz na konst. l-hodnotu" << endl;
}


int main()
{
	int x = 8;
	const int d = 99;
	f(5);
	f(d);
	f(x);
	f(+x);
}