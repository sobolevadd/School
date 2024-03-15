// Soubor 15-00E\MATICE.H
// Trida matice stejna jako v 15-00A.cpp, 
// doplnena metoda Vypis()

#ifndef _MAT_H_
	#define _MAT_H_
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

	void Vypis();
};

#endif