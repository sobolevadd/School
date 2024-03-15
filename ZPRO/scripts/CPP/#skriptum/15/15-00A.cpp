// Soubor 15-00A.cpp
// Trida matice
// definovany operatory +, * pro nasobeni matice*cislo
// * pro nasobeni cislo*matice (jako volna funkce)
// [] indexovani
// () se dvema parametry (slouzi jako indexovani)
// = prirazovani

#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <exception>
using namespace std;


class matice {
	enum {pocet = 10,}; 			// Velikost ��dku a sloupce matice
	double (*p)[pocet]; 			// Ukazatel na pole
public:
	friend matice operator*(const matice& m, const matice& n);
	matice(double d = 0.0);		// Konstruktor
	matice(const matice&);		// Kop�rovac� konstruktor
	~matice() {delete[] p;}		// Destruktor
	matice operator+(const matice&) const;		// S��t�n� matic
	matice operator*(const double) const;		// N�soben� ��slem
	double* operator[](int); 					// Indexov�n�
	matice operator~() const;	// Oper�tor transposice
	double& operator ()(int, int) const; 	// Oper�tor vol�n� funkce (jako indexovani)
	matice& operator=(const matice&);		// P�i�azovac� oper�tor
};

matice::matice(double d): p(new double[pocet][pocet])
{
	for(int i = 0; i < pocet; i++)
		for(int j = 0; j < pocet; j++) p[i][j] = 0;
	if(d)
	{ for(int i = 0; i < pocet; i++) p[i][i] = d;
	}
}

matice::matice(const matice& m)
: p(new double[pocet][pocet])
{
	for(int i = 0; i < pocet; i++)
		for(int j = 0; j < pocet; j++) p[i][j] = m.p[i][j];
}

matice matice::operator~() const
{
	matice M(*this); 				// Pomocn� instance - kopie operandu
	for(int i = 0; i < pocet; i++)
		for(int j = i+1; j < pocet; j++)
		{ 	// Vlastn� transposice
			double a = M.p[i][j];
			M.p[i][j] = M.p[j][i];
			M.p[j][i] = a;
		}
	return M; 							// Vr�t� pomocnou instanci
}


matice matice::operator+(const matice& m) const
{
	matice M(*this);						// Lok�ln� kopie lev�ho operandu
	for(int i = 0; i < pocet; i++)
		for(int j = 0; j < pocet; j++) M.p[i][j] += m.p[i][j];
	return M;
}

matice matice::operator*(const double d) const
{
	matice M(*this);						// Lok�ln� kopie lev�ho operandu
	for(int i = 0; i < pocet; i++)
		for(int j = 0; j < pocet; j++) M.p[i][j] *= d;
	return M;
}

matice operator*(const matice& m, const matice& n)
{
	matice M;
	for(int i = 0; i < matice::pocet; i++)
		for(int j = 0; j < matice::pocet; j++)
			for(int k = 0; k < matice::pocet; k++)
				M.p[i][j] += m.p[i][k]*n.p[k][j];
	return M;
}


inline matice operator*(double d, matice m)
{ return m * d;
}

double * matice::operator[](int i)
{	
	return p[i];
}

double& matice::operator()(int i, int j) const
{ 
	if((i < 0) || (j < 0) || (i >= pocet) || (j >= pocet)) 
			throw runtime_error("index mimo meze");
	return p[i][j];
}

matice& matice::operator=(const matice& m)
{
	for(int i = 0; i < pocet; i++)
		for(int j = 0; j < pocet; j++) p[i][j] = m.p[i][j];
	return *this;
}


int main()
{
	try{
		matice M1, M2;
		M1[0][0] = 11;
		M1(0, 1) = 13;
		M1 = ~M2;
	}
	catch(exception e)
	{
		cerr << e.what() << endl;
	}
	return 0;
}
