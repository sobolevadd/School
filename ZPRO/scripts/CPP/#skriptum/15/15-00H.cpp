// Soubor 15-00H.cpp
// Operatory new a delete a new[] a delete[]
// Trida pom obsahuje tyto operatory 
// alokace do "areny"  (pole k tomu urcene) a 
// neuvolnuji se


class pom {
	int i; 										// N�jak� data
	enum {velikost = 1000};			// Velikost ar�ny
public:
	pom():i(0){}											// Konstruktor a destruktor
	~pom(){}
	void* operator new(size_t s);
	void operator delete(void *p){};
	void* operator new[](size_t s);
	void operator delete[](void *p){}
};
void* pom::operator new(size_t s)
{
	static char arena[velikost]={0,}; 		// Prostor pro alokaci
	static int pos = 0;					// Ukazatel na aktu�ln� pozici
	int i = pos+s > velikost ? 0 : pos;
	pos = i+s;
	return &arena[i];
}

void* pom::operator new[](size_t s)
{
	return operator new(s); 						// Vol�me pom::new
}


int main()
{
	pom* p = new pom;
	p = new pom;
	p = new pom[3];
}