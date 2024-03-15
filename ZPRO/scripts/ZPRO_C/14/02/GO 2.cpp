#include "GO.h"

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