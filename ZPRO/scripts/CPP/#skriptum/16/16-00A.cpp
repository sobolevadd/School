// Soubor 16-00A.cpp
// Sablona tridy matice, nekterych metod
// a statickeho atributu

template<typename T, int pocet = 10>
class matice {
	T (*p)[pocet];
 	static int pocet_matic; 				// Skuteèný poèet instancí
 	friend matice operator*(const matice& m, const matice& n);
public:
 	typedef T typ_prvku;						// Zveøejníme typ prvkù matice
 	matice(T d = 0.0);
 	matice(const matice&);
 	~matice() {delete[] p; pocet_matic--;}
 	matice operator+(const matice&) const;
	matice operator*(const T) const;
 	matice operator~() const;
 	T& operator ()(int, int) const;
 	T* operator[](int);
 	static int kolik(){return pocet_matic;}	// Vrátí poèet instancí
 	matice& operator=(const matice&);
};

template<typename T, int pocet>
matice<T, pocet>
matice<T, pocet>::operator+(const matice<T, pocet>& m) const
{ 
	matice<T, pocet> M(*this);
	for(int i = 0; i < pocet; i++)
		for(int j = 0; j < pocet; j++) M.p[i][j] += m.p[i][j];
	return M;
}

template<typename T, int pocet>
matice<T, pocet>&
matice<T, pocet>::operator=(const matice<T, pocet>& m)
{
	for(int i = 0; i < pocet; i++)
		for(int j = 0; j < pocet; j++) p[i][j] = m.p[i][j];
	return *this;
};

template<typename T, int pocet>
matice<T, pocet>::matice(T d)
: p(new T[pocet][pocet])
{ 
	for(int i = 0; i < pocet; i++)
		for(int j = 0; j < pocet; j++) p[i][j] = 0;
			if(d != 0) for(int i = 0; i < pocet; i++) p[i][i] = d;
	pocet_matic++;
}

template<class T, int pocet> int matice<T,pocet>::pocet_matic = 0;

int main()
{
	matice<int, 2> M;
}