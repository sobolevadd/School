//priklady na ruzne druhy cyklu
// vzdy se posita sinus pomoci
// Taylorovy rady 

#define EPS 1e-7
#define PI 3.1415926
#include <math.h>

double Sin(double x)
{
 double xx = -x*x;
 double s = x, t=x;
 int i = 1;
 while(fabs(t) > EPS) {
  t *= xx/(i+1)/(i+2);
  s+= t;
  i+=2;
 }
 return s;
}

double SIn(double x)
{
 double xx = -x*x;
 double s = x, t=x;
 int i = 1;
 do {
  t *= xx/(i+1)/(i+2);
  s+= t;
  i+=2;
 } while (fabs(t) > EPS);
 return s;
}

double SIN(double x)
{
 double xx = -x*x;
 double s = x, t=x;
 int i = 1;
 for(;fabs(t) > EPS; s+=t,i+=2) t *= xx/(i+1)/(i+2);
 return s;
}

int main()
{
 double s = Sin(1);
 double ss = sin(1);
 double S = SIn(1);
 double SS = SIN(1);
 return 0;
}