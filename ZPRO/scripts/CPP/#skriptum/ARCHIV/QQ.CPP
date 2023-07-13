// Priklad na typedef
typedef int *Fun(int, int);

Fun* F(Fun*, Fun*);

int *(*(*Q)(int *(*)(int,int), int *(*)(int,int)))(int, int);



void main() {
 Q = F;
}

Fun* F(Fun*a, Fun*b){return a;};
