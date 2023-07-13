// Soubor 19-03C.cpp
// Vyhledávání funkcí v prostoru jemn parametrù

namespace A
{
	class X{};
	void f(X){}
	X operator+(X a, X b){return X();}
};
int main()
{
	using A::X;
	X a, b, c;
	f(a);	// Správné, ale nìkteré pøekladaèe nepøeloží
	c = a+b;
}
