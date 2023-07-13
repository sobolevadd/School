// Soubor 16-01.cpp
// Parcialni usporadani sablon volnych funkci
// Prevzato ze standardu

template<class T> struct A { A(){} };
template<class T> void f(T){}
template<class T> void f(T*){}
template<class T> void f(const T*){}
template<class T> void g(T){}
template<class T> void g(T&){}
template<class T> void h(const T&){}
template<class T> void h(A<T>&){}

int main() {
	const int *p;
	float x;
	A<int> z;
	const A<int> z2;
	f(p); 	// f(const T*) je specializovanejsi nez f(T) nebo f(T*)
	//g(x);	// Nejednoznacne: g(T), nebo g(T&)?
	h(z);	// vybere h(A<T>&)
	h(z2);	// h(const T&), protože h(A<T>&) volat nelze 
} 
