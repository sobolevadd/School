// Soubor 19-03C.cpp
// Vyhled�v�n� funkc� v prostoru jemn parametr�

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
	f(a);	// Spr�vn�, ale n�kter� p�eklada�e nep�elo��
	c = a+b;
}
