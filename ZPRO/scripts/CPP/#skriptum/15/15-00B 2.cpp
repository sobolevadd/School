// Soubor 15-00B.cpp 
// Pretezovani operatoru ++ pro vyctovy typ

enum dny {	pondeli, utery, streda, ctvrtek, 
					patek, sobota, nedele, _dny};

dny operator++(dny& d) 			// Prefixov� oper�tor
{ 													// Zm�n� operand a tuto hodnotu vr�t�
	int i = d+1;
	return d = (i == _dny ? pondeli : (dny)i);
}

dny operator++(dny& d, int)	// Postfixov� oper�tor
{
	dny D = d; 				// Zapamatuje si p�vodn� hodnotu operandu
	int i = d+1; 			// Zm�n� operand
	d = (i == _dny ? pondeli : (dny)i);
	return D; 					// Vr�t� p�vodn� hodnotu
}

int main()
{
	dny d = pondeli;
	dny u = ++d;
	u = nedele;
	d = u++;
	return 0;
}