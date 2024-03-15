#include "cplx.h"
#include <math.h>
#include <stdexcept>
using namespace std;

namespace knihovna
{
	constexpr cplx::cplx(double _re, double _im)
		:re(_re), im(_im)
	{}

	double cplx::Re()
	{
		return re;
	}

	double cplx::Im()
	{
		return im;
	}

	cplx::operator double()
	{
		if (im != 0)
		{
			throw invalid_argument("nenulova imaginarni cast");
		}
		return re;
	}

	cplx cplx::operator-()
	{
		return cplx(-re, -im);
	}

	cplx conj(cplx a)
	{
		return cplx(a.Re(), -a.Im());
	}

	cplx operator+(cplx a, cplx b)
	{
		return cplx(a.Re() + b.Re(), a.Im() + b.Im());
	}

	cplx operator-(cplx a, cplx b)
	{
		return cplx(a.Re() - b.Re(), a.Im() - b.Im());
	}

	cplx operator*(cplx a, cplx b)
	{
		return cplx(a.Re() * b.Re() - a.Im() * b.Im(), a.Re() * b.Im() + a.Im() * b.Re());
	}

	cplx operator / (cplx a, double x)
	{
		return cplx(a.Re() / x, a.Im() / x);
	}

	cplx operator/(cplx a, cplx b)
	{
		return a*conj(b) / (b*conj(b)).Re();
	}

	double abs(cplx a)
	{
		return sqrt(a.Re()*a.Re() + a.Im()*a.Im());
	}

	ostream& operator << (ostream& proud, cplx z)
	{
		return proud << z.Re() << " + " << z.Im() << "i";
	}

	/*
	istream& operator >> (istream& proud, cplx& z)
	{
	double re, im;
	proud >> re >> im;
	z = cplx(re, im);
	return proud;
	}
	*/

	istream& operator >> (istream& proud, cplx& z)
	{
		return proud >> z.re >> z.im;
	}

	cplx operator "" _i(long double x)
	{
		return cplx(0.0, x);
	}

	cplx operator "" _i(unsigned long long x)
	{
		return cplx(0.0, (double)x);
	}
}