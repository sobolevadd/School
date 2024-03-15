// priklad na sablonu objektoveho typu

template<class T, int N> class Alfa {
  T d[N][N];
 public:
  Alfa(double q = 0);
  T* operator[](int i)
   {
    return d[i];
   }
};

template<class R, int M> Alfa<R,M>::Alfa(double q)
{
 for(int i = 0; i < N; i++)
   for(int j = 0; j < N; j++) d[i][j]=q;
}


typedef Alfa<int, 2> Mat;

void main()
{
 Mat a(2), b(6);
 b[1][1] = 11;
}