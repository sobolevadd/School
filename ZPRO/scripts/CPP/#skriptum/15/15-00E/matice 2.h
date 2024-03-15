// Soubor 15-00E\MATICE.H
// Trida matice stejna jako v 15-00A.cpp, 
// doplnena metoda Vypis()

#ifndef _MAT_H_
	#define _MAT_H_
class matice {
	enum {pocet = 10,}; 			// Velikost øádku a sloupce matice
	double (*p)[pocet]; 			// Ukazatel na pole
public:
	friend matice operator*(const matice& m, const matice& n);
	matice(double d = 0.0);		// Konstruktor
	matice(const matice&);		// Kopírovací konstruktor
	~matice() {delete[] p;}		// Destruktor
	matice operator+(const matice&) const;		// Sèítání matic
	matice operator*(const double) const;		// Násobení èíslem
	double* operator[](int); 					// Indexování
	matice operator~() const;	// Operátor transposice
	double& operator ()(int, int) const; 	// Operátor volání funkce (jako indexovani)
	matice& operator=(const matice&);		// Pøiøazovací operátor

	void Vypis();
};

#endif