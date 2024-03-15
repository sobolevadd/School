#include <iostream>
#include "Bod.h"

using namespace std;

Bod::Bod(int bar, int _x, int _y)
	: GO(bar)
{
	SetX(_x);
	SetY(_y);
}

void Bod::SetY(int _y)
{
	y = _y;
}

int Bod::GetY()
{
	return y;
}

void Bod::SetX(int _x)
{
	x = _x;
}

int Bod::GetX()
{
	return x;
}

void Bod::Nakresli()
{
	cout << "(" << x << ", " << y << ")";
}