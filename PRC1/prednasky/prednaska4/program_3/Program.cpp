#define NDEBUG
#include <iostream>
#include <assert.h>
#include <exception>
#include <stdexcept>
#include <algorithm>

using namespace std;

//void print(int pole[]) // Nelze: prekladac nezna velikost pole (nevidi pole, ale ukazatel na ne)
//{
//	for (int i : pole) // Nelze
//	{
//
//	}
//}

void f(int pole[]) // Predava se ukazatel
{
	cout << sizeof(pole) << endl;
}

int factorial1(int n)
{
	assert(n >= 0);
	int result = 1;
	while (n>1)
	{
		result *= n--;
	}
	return result;
}

void turn(int pole[], int delka)
{
	for (int i = 0, j = delka - 1; i < j; i++, j--)
	{
		swap(pole[i], pole[j]);
	}
}

int factorial2(int n)
{
	if (n < 0)
	{
		throw out_of_range("Negative parametr of factorial");
		//throw exception("Negative parametr of factorial");
	}
	int result = 1;
	while (n > 1)
	{
		result *= n--;
	}
	return result;
}

int main()
{
	//cout << faktori�l1(-5) << endl;
	try {
		cout << factorial2(-5) << endl;
	}
	catch (out_of_range exception)
	{
		cout << exception.what() << endl;
	}
	catch (...)
	{
		cout << "Not defined error" << endl;
	}
	begin:
	int A[] = { 1,2,3,4,5,6 };
	auto lenght = sizeof(A)/sizeof(int);
	turn(A, lenght);
	f(A);
	for (int i : A)
	{
		cout << i << " ";
	}
	cout << endl;
	//goto za��tek;  // to by byl nekone�n� cyklus

	for (int &i : A)
	{
		i++;
	}
	for (int i : A)
	{
		cout << i << " ";
	}
	end:
	cout << endl;

	//asm("mov EAX, 0");
}