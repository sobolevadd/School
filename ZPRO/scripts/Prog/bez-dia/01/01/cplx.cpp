#include "cplx.h"
#include <math.h>

namespace knihovna
{
	cplx::cplx(double _re, double _im)
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

	cplx cplx::conj()
	{
		return cplx(re, -im);
	}

	cplx cplx::operator+(cplx a)
	{
		return cplx(re + a.re, im + a.im);
	}

	cplx cplx::operator-(cplx a)
	{
		return cplx(re - a.re, im - a.im);
	}

	cplx cplx::operator*(cplx a)
	{
		return cplx(re * a.re - im * a.im, re * a.im + im * a.re);
	}

	cplx cplx::operator/(double x)
	{
		return cplx(re / x, im / x);
	}

	cplx cplx::operator/(cplx z)
	{
		//double d = z.re*z.re + z.im*z.im;
		return (*this)*z.conj() / (z*z.conj()).re;
	}

	double cplx::abs()
	{
		return sqrt(re*re + im*im);
	}
}