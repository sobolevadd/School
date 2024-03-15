#define N 10

// priklady na kopirovaci konstruktor, destrukor
// operator prirazeni a jine


class Pole {
  double *pole;
  friend Pole operator* (double, Pole); // Zbytecna deklarace
 public:
  Pole(double = 0.0);
  Pole(Pole&);
  ~Pole();
  double& operator[] (int);
  Pole& operator=(Pole&);
  Pole operator* (double);
};

Pole::Pole(double d) // konverzni konstruktor
{
  pole = new double [N];
  for(int i = 0; i < N; i++)
     pole[i] = d;
}

Pole::Pole(Pole& p)  // kopirovaci konstruktor
{
 pole = new double [N];
 for(int i = 0; i < N; i++)
     pole[i] = p.pole[i];
}

Pole::~Pole()   // Destruktor
{
 delete pole;
}

double &Pole::operator[](int i)
{                           // op indexovani
 return pole[i];
}

Pole& Pole::operator=(Pole& p) // prirazovaci op
{
 for(int i = 0; i < N; i++)
      pole[i] = p.pole[i];
 return *this;
}

// op nasobeni cislem zprava
Pole Pole::operator*(double d)
{
 Pole q = *this;
 for(int i = 0; i < N; i++) q[i] *= d;
 return q;
}

// nasobeni cislem zleva
Pole operator*(double d, Pole p)
{
 return p*d;
}


void main()
{
 Pole p, q(1);
 p = 6.0;
 Pole r = p;
 r[1] = 9.9;
 q = 8*r;

}
