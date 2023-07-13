class Hlídka
{
public:
	Hlídka()
	{
		cout << "Postavena hlídka" << endl;
		ii++;
	}
	~Hlídka()
	{
		cout << "Hlídka zrušena" << endl;
	}
	int h = 3;
};

double sin(double x, double epsilon)
{
	double výsledek = x;
	double sèítanec = x;
	int i = 2;
	do
	{
		sèítanec = -sèítanec*x*x / i / (i + 1);
		výsledek += sèítanec;
		i += 2;
	} while (abs(sèítanec) > epsilon);
	return výsledek;
}

char* otoè(char* text, int n)
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
		cout << "Uctivá poklona";
	}
	cout << endl;
}

char* na_velká(char* txt)
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