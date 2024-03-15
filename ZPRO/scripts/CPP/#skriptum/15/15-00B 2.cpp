// Soubor 15-00B.cpp 
// Pretezovani operatoru ++ pro vyctovy typ

enum dny {	pondeli, utery, streda, ctvrtek, 
					patek, sobota, nedele, _dny};

dny operator++(dny& d) 			// Prefixový operátor
{ 													// Zmìní operand a tuto hodnotu vrátí
	int i = d+1;
	return d = (i == _dny ? pondeli : (dny)i);
}

dny operator++(dny& d, int)	// Postfixový operátor
{
	dny D = d; 				// Zapamatuje si pùvodní hodnotu operandu
	int i = d+1; 			// Zmìní operand
	d = (i == _dny ? pondeli : (dny)i);
	return D; 					// Vrátí pùvodní hodnotu
}

int main()
{
	dny d = pondeli;
	dny u = ++d;
	u = nedele;
	d = u++;
	return 0;
}