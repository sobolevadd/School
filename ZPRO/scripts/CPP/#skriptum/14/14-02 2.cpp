// Soubor 14-02.cpp 
// Ukazuje deklaraci metody jako inline (vložené)
// - zápis definice v tìle tøídy, nebo
// - modifikátor imline
// Pouze konstruktor zde není inline

class X {
	int x;
public:
	X(int _x = 0);								// konstruktor není inline
	inline int VratMinus();						// Modifikátor inline
	void NastavHodnotu(int _x){ x = _x; }		// Zápis v tìle tøídy
	void ZmenZnamenko() { x = -x; }				// Zápis v tìle tøídy
};
X::X(int _x): x(_x){}
int X::VratMinus(){ ZmenZnamenko(); return x; }

int main()
{
}