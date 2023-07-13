// Soubor cplx.cpp
// implementace metod tridy cplx
// a operatoru << a >>
// operator >> ocekava dvojici realnych cisel
// oddelenych mezerou nebo prechodem na novy radek

#include "cplx.h"

// konstruktor
cplx::cplx(double r, double i)
: re(r), im(i)
{
 re = r; im = i;
}

// operator +
cplx cplx::operator+(cplx c)
{
 return cplx(re+c.re, im+c.im);
}

// operator -
cplx cplx::operator-(cplx c)
{
 return cplx(re-c.re, im-c.im);
}

// operator *
cplx cplx::operator*(cplx c)
{
 double D = SQR(c.re) + SQR(c.im);
 return cplx((re*c.re+im*c.im)/D, (-re*c.im+im*c.re)/D);
}

// unarni -
cplx cplx::operator-()
{
 return cplx(-re, -im);
}

// Operátory pro vstup, resp. vystup komplexnich cisel
// pomoci proudu

ostream& operator<<(ostream& Str, cplx c)
{
	Str << c.Re() << "+" << c.Im() << "*i" ; 
	return Str;
}

istream& operator>>(istream& Str, cplx &x)
{
	double d, e;
	Str >> d >> e;
	x = cplx(d, e);
	return Str;
}