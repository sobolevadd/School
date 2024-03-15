// Soubor 15-00E\MATICE.CPP
// Trida matice stejna jako v 15-00A.cpp, 
// doplnena metoda Vypis()

#include <stdexcept>
#include <iostream>
#include "matice.h"
using namespace std;

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
	matice M(*this); 				// Pomocná instance - kopie operandu
	for(int i = 0; i < pocet; i++)
		for(int j = i+1; j < pocet; j++)
		{ 	// Vlastní transposice
			double a = M.p[i][j];
			M.p[i][j] = M.p[j][i];
			M.p[j][i] = a;
		}
	return M; 							// Vrátí pomocnou instanci
}


matice matice::operator+(const matice& m) const
{
	matice M(*this);						// Lokální kopie levého operandu
	for(int i = 0; i < pocet; i++)
		for(int j = 0; j < pocet; j++) M.p[i][j] += m.p[i][j];
	return M;
}

matice matice::operator*(const double d) const
{
	matice M(*this);						// Lokální kopie levého operandu
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


void matice::Vypis()
{
	for (int i = 0; i < pocet; i++)
	{
		for (int j = 0; j < pocet; j++)
			cout << (*this)(i,j);
		cout << endl;
	}
}