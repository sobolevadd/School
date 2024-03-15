// Ne‘ douc¡ vlastnosti p©edk– - 2. ©e¨en¡
// klient - server: m¡sto dˆdˆn¡ atribut

extern "C" {
   int printf( char * ... );
   void exit ( int );
   void *realloc(void*, unsigned);
}

void alarm()
{
  printf("nen¡ dost pamˆti");
  exit(1);
}

class Pole {
  int vel;
  double *p;
 public:
  Pole( int = 10 );
  double& operator[] ( int );
  void zmenVelikost( int novaVel );
};

Pole::Pole( int i ) : vel(i)
{
 p = new double[vel];
 if(!p) alarm();
}
void Pole::zmenVelikost( int novaVel )
{
 double *pp = (double *)realloc(p, novaVel);
 if(!pp) alarm();
}

double& Pole::operator[]( int i )
{
 return p[i];
}
// *************************************************************

// Klient - server

class Zasobnik {
    int vrchol;
    Pole pole;
 public:
    Zasobnik( int vel ): pole(vel)
    { vrchol = 0;
    }
    void vloz( double co )
    {pole[vrchol++] = co;
    }
    double vyjmi( void )
    {return pole[--vrchol];
    }
};

void main()
{
 Zasobnik a(10);
 a.vloz(11);
 a.vloz(22.2);
 double c = a.vyjmi();
 c = a.vyjmi();
// c = a[1]; // Teƒ u‘ to nejde
}

