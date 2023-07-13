// Soubor 16-01B.cpp
// Parcialni specializace sablon objektovych typu


template <typename T, int n>		// �. 1 (prim�rn� �ablona)
class vektor {		
T p[n];
	public:
vektor(T t = 0){ for(int i = 0; i < n; i++) p[i] = t; }
T& operator[](int i){ return p[i]; }
// ...
};

template <typename T, int n>		// �. 2 (prvn� specializace)
class vektor<T*, n>
{ 
	T *p[n];
public:
	vektor(T t = 0){ for(int i = 0; i < n; i++) p[i] = new T(t); }
	T& operator[](int i){ return *p[i]; }
};

template <typename T>					// �. 3 (dal�� specializace)
class vektor<T*, 2>
{ 
public:
	vektor(){}
	// N�jak� definice... 
};

int main()
{
		vektor<int, 10> vi; 					// Pou�ije se �ablona �. 1
		vektor<long*, 10> vlp; 				// �ablona �. 2, T == long
		vektor<double*, 2> vdp; 			// �ablona �. 3, T == double
	
		return 0;
}