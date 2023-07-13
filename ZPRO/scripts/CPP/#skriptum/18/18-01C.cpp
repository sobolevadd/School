// Soubor 18-01C.cpp
// Pouziti operatoru const_cast

// Diky pretypovani na konstantu se zavola 
// metoda f() const misto f()

struct S{
	void f(){}
	void f() const{}
};
int main(){
 	S ss;
 	ss.f(); 											
 	const_cast<const S&>(ss).f();	
 	return 0;
}
