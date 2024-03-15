#include <iostream.h>
#include <process.h>

void Chyba(){
 cerr << "Chyba!!!";
 exit(1);
}

const n=3;

class Mat {
  double p[n][n];
 public:
  Mat(double=0.0);
  double& operator()(int, int);
  double operator()(int, int) const;
  double *operator[](int);
};

Mat::Mat(double d){
 for(int i = 0; i < n; i++)
 for(int j = 0; j < n; j++)p[i][j]=0.0;
 for(int j = 0; j < n; j++)p[j][j]=d;
}

double& Mat::operator()(int i, int j){
 if(i<0 || j < 0 || i >= n || j > n) Chyba();
 return p[i][j];
}

double Mat::operator()(int i, int j) const {
 if(i<0 || j < 0 || i >= n || j > n) Chyba();
 return p[i][j];
}

double *Mat::operator[](int i){
 return p[i];
}

void main(){
 Mat m(9);
 m(0,0)=11.;
 const Mat mm(8);
 m(2,2)=mm(1,1);
 m[0][0]=22;
 m=33;
}