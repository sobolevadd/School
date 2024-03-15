#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

class cplx
{
	//friend int main();
	double re, im;
public:
	cplx(double _re, double _im);
	double GetRe();
	double GetIm();
	void SetRe(double _re);
	void SetIm(double _im);
};

cplx::cplx(double _re, double _im)
	: re(_re), im(_im)
{
}

double cplx::GetIm()
{
	return im;
}


double cplx::GetRe()
{
	return re;
}

void cplx::SetRe(double _re)
{
	re = _re;
}

void cplx::SetIm(double _im)
{
	im = _im;
}

int main()
{
	cplx z (9,8);
	//z.re = 9;              // CHYBA, je-li deklarace friend zakomentována
	z.SetRe(9);				 // Vždy správné
}