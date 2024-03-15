// Soubor 16-00B.cpp
// Priklad vnorene sablony


template<typename T> class cislo
{ 
	T n;
public:
	cislo(T m=0): n(m){}
	// Vnorena sabolona operatoru pretypovani
	template<typename R> operator cislo<R>();
	// ... a další metody ...
};


template<typename T>
	template<typename R>
		cislo<T>::operator cislo<R>() { return cislo<R>(n); }


int main()
{
	cislo<int> c(1);
	cislo<double> d;
	d = c;			// pouzije se operator pretypovani
				// vytvoreny podle vnorene sablony
	return 0;
}