#include <iostream>
#include <stdlib.h>

using namespace std;

void neprohod(int a, int b)
{
	int c = a;
	a = b;
	b = c;
}

void prohod(int * a, int * b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

void vypis(const char * text, int a, int b)
{
	cout << text << endl; 
	cout << "a = " << a << "; b = " << b << endl;
}


int main()
{
	system("CHCP 1250 > NUL");
	int a = 9, b = 8;
	vypis("Na po��tku: ", a, b);
	neprohod(a, b);
	vypis("Po zavol�n� funkce neprohod(): ", a, b);
	prohod(&a, &b);
	vypis("Po zavol�n� funkce prohod(): ", a, b);
}