// p©¡klad na ¨ablonu ©adov‚ funkce

template<class T> T min(T a, T b)
{
 return a < b ? a : b;
}


inline sqr(double x)
{
 return x*x;
}

class cplx {
   double re, im;
 public:
   cplx(double = 0, double = 0);
   friend cplx operator+(cplx, cplx);
   int operator<(cplx);
};

cplx::cplx(double r, double i)
{
 re = r; im = i;
}

int cplx::operator< (cplx c)
{
 return sqr(re)+sqr(im) < sqr(c.re)+sqr(c.im);
}

cplx operator+(cplx c, cplx d)
{
 return cplx(c.re+d.re, c.im + d.im);
}


char* min(char* a, char* b)  // to je taky instance ¨ablony
{
 return *a < *b? a : b;
}



//int min(int, int);
//cplx min(cplx, cplx);

void main()
{
 int a = 11, b = 66, c;
 double aa = 1.1, bb = 2.2, cc;
 cplx ccc, aaa(1,1), bbb(1);
 char * ac="ahoj", *bc = "chacha";
 ccc = aaa+1;
 c = min(a,b);
 cc = min(aa,bb);
 ccc = min(aaa, bbb);
 char * ca= min(ac, bc);
}