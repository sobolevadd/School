class Hlidka
{
public:
	Hlidka()
	{
		cout << "Postavena hlidka" << endl;
		ii++;
	}
	~Hlidka()
	{
		cout << "Hlidka zrusena" << endl;
	}
	int h = 3;
};

double sin(double x, double epsilon)
{
	double vysledek = x;
	double scitanec = x;
	int i = 2;
	do
	{
		scitanec = -scitanec*x*x / i / (i + 1);
		vysledek += scitanec;
		i += 2;
	} while (abs(scitanec) > epsilon);
	return vysledek;
}

char* otoc(char* text, int n)
{
	for (int i = 0, j = n-1; i < j; i++, j--)
	{
		swap(text[i], text[j]);
	}
	return text;
}

void Pozdrav(int n)
{
	switch (n)
	{
	case 0:
	case 1:
		cout << "Nazdar";
	case 2:
		cout << "Ahoj";
	default:
		cout << "Uctiva poklona";
	}
	cout << endl;
}

char* na_velka(char* txt)
{
	for (int i = 0; txt[i]; i++)
	{
		if ((txt[i] >= 'a') && (txt[i] <= 'z'))
		{
			txt[i] -= 'a' - 'A';
		}
	}
	return txt;
}