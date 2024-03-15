#ifndef __CPLX_H__
#define __CPLX_H__

#include <iostream>
#include <math.h>

using namespace std;

namespace knihovna
{
	template<typename T>
	class cplx
	{
	public:
		cplx(T _re = 0, T _im = 0);
		T Re();
		T Im();
	private:
		T re;
		T im;
		friend istream& operator >> <T> (istream& proud, cplx<T>& z);
	};

	template<typename T>
	cplx<T>::cplx(T _re, T _im)
		:re(_re), im(_im)
	{}

	template<typename T>
	T cplx<T>::Re()
	{
		return re;
	}

	template<typename T>
	T cplx<T>::Im()
	{
		return im;
	}

	template<typename T> 
	cplx<T> operator + (cplx<T> a, cplx<T> b)
	{
		return cplx<T>(a.Re() + b.Re(), a.Im() + b.Im());
	}

	template<typename T> cplx<T> 
	operator - (cplx<T> a, cplx<T> b)
	{
		return cplx(a.Re() - b.Re(), a.Im() - b.Im());
	}

	template<typename T> 
	cplx<T> operator * (cplx<T> a, cplx<T> b)
	{
		return cplx<T>(a.Re() * b.Re() - a.Im() * b.Im(), a.Re() * b.Im() + a.Im() * b.Re());
	}
	
	template<typename T> 
	cplx<T> operator / (cplx<T> a, T x)
	{
		return cplx<T>(a.Re() / x, a.Im() / x);
	}

	template<typename T> 
	cplx<T> operator / (cplx<T> a, cplx<T> b)
	{
		return a*conj(b) / (b*conj(b)).Re();
	}

	template<typename T> 
	T abs(cplx<T> a)
	{
		return sqrt(a.Re()*a.Re() + a.Im()*a.Im());
	}
	
	template<typename T> 
	cplx<T> conj(cplx<T> a)
	{
		return cplx<T>(a.Re(), -a.Im());
	}

	template<typename T> 
	ostream& operator << (ostream& proud, cplx<T> z)
	{
		return proud << z.Re() << " + " << z.Im() << "i";
	}

	template<typename T> 
	istream& operator >> (istream& proud, cplx<T>& z)
	{
		return proud >> z.re >> z.im;
	}
	
	/*template<typename T>
	istream& operator >> (istream& proud, cplx<T>& z)
	{
		T re, im;
		proud >> re >> im;
		z = cplx<T>(re, im);
		return proud;
	}*/

}
#endif