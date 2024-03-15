#ifndef __CPLX_H__
#define __CPLX_H__

#include <iostream>

using namespace std;

namespace knihovna
{
	class cplx
	{
	public:
		constexpr cplx(double _re = 0, double _im = 0);
		double Re();
		double Im();
		explicit operator double();
		cplx operator-();
	private:
		double re;
		double im;
		friend istream& operator >> (istream& proud, cplx& z);
	};

	cplx operator + (cplx a, cplx b);
	cplx operator - (cplx a, cplx b);
	cplx operator * (cplx a, cplx b);
	cplx operator / (cplx a, double x);
	cplx operator / (cplx a, cplx b);
	double abs(cplx z);
	cplx conj(cplx z);
	ostream& operator << (ostream& proud, cplx z);
	istream& operator >> (istream& proud, cplx& z);
	cplx operator "" _i(long double x);
	cplx operator "" _i(unsigned long long x);
}
#endif
