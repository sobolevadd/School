#ifndef __CPLX_H__
#define __CPLX_H__
namespace knihovna
{
	class cplx
	{
	public:
		cplx(double _re = 0, double _im = 0);
		double Re();
		double Im();
		cplx operator + (cplx a);
		cplx operator - (cplx a);
		cplx operator * (cplx a);
		cplx operator / (double x);
		cplx operator / (cplx a);
		double abs();
		cplx conj();
	private:
		double re;
		double im;
	};
}
#endif