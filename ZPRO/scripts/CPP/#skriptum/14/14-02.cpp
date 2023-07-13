// Soubor 14-02.cpp 
// Ukazuje deklaraci metody jako inline (vlo�en�)
// - z�pis definice v t�le t��dy, nebo
// - modifik�tor imline
// Pouze konstruktor zde nen� inline

class X {
	int x;
public:
	X(int _x = 0);								// konstruktor nen� inline
	inline int VratMinus();						// Modifik�tor inline
	void NastavHodnotu(int _x){ x = _x; }		// Z�pis v t�le t��dy
	void ZmenZnamenko() { x = -x; }				// Z�pis v t�le t��dy
};
X::X(int _x): x(_x){}
int X::VratMinus(){ ZmenZnamenko(); return x; }

int main()
{
}