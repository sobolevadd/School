class Hl�dka
{
public:
	Hl�dka()
	{
		cout << "Postavena hl�dka" << endl;
		ii++;
	}
	~Hl�dka()
	{
		cout << "Hl�dka zru�ena" << endl;
	}
	int h = 3;
};

double sin(double x, double epsilon)
{
	double v�sledek = x;
	double s��tanec = x;
	int i = 2;
	do
	{
		s��tanec = -s��tanec*x*x / i / (i + 1);
		v�sledek += s��tanec;
		i += 2;
	} while (abs(s��tanec) > epsilon);
	return v�sledek;
}

char* oto�(char* text, int n)
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
		cout << "Uctiv� poklona";
	}
	cout << endl;
}

char* na_velk�(char* txt)
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