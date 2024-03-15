// Ne‘ douc¡ vlastnosti p©edk– - 1. ©e¨en¡
// Nech me to plavat...

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

class Zasobnik:  public Pole {
    int vrchol;
 public:
    Zasobnik( int vel ): Pole(vel)
    { vrchol = 0;
    }
    void vloz( double co )
    {(*this)[vrchol++] = co;
    }
    double vyjmi( void )
    {return (*this)[--vrchol];
    }
};

void main()
{
 Zasobnik a(10);
 a.vloz(11);
 a.vloz(22.2);
 double c = a.vyjmi();
 c =  a.vyjmi();
 c = a[1]; // Tohle by nemˆlo b˜t mo‘n‚
}

