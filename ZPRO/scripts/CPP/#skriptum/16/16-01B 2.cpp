// Soubor 16-01B.cpp
// Parcialni specializace sablon objektovych typu


template <typename T, int n>		// è. 1 (primární šablona)
class vektor {		
T p[n];
	public:
vektor(T t = 0){ for(int i = 0; i < n; i++) p[i] = t; }
T& operator[](int i){ return p[i]; }
// ...
};

template <typename T, int n>		// è. 2 (první specializace)
class vektor<T*, n>
{ 
	T *p[n];
public:
	vektor(T t = 0){ for(int i = 0; i < n; i++) p[i] = new T(t); }
	T& operator[](int i){ return *p[i]; }
};

template <typename T>					// è. 3 (další specializace)
class vektor<T*, 2>
{ 
public:
	vektor(){}
	// Nìjaká definice... 
};

int main()
{
		vektor<int, 10> vi; 					// Použije se šablona è. 1
		vektor<long*, 10> vlp; 				// Šablona è. 2, T == long
		vektor<double*, 2> vdp; 			// Šablona è. 3, T == double
	
		return 0;
}