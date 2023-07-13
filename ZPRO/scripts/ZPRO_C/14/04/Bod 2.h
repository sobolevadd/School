#ifndef __BOD_H__
#define __BOD_H__
#include "GO.h"

class Bod : public GO
{
	int x, y;
public:
	Bod(int bar, int _x, int _y);
	virtual void Nakresli();
	int GetX();
	void SetX(int _x);
	int GetY();
	void SetY(int bar);
};
#endif