#include <iostream>
#include "GO.h"

using namespace std;

GO::GO(int bar)
{
	SetBarva(bar);
}

int GO::GetBarva()
{
	return barva;
}

void GO::SetBarva(int bar)
{
	barva = bar;
}

void GO::Nakresli()
{
	cout << "{" << barva << "}";
}