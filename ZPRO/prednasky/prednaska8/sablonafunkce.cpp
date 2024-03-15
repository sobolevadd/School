#include <iostream>
using namespace std;

void vypis (int a, int b, int c){
    cout << a << endl << b << endl << c << endl;
}

static int faktorial(int n){
    return n + 1;
}

auto faktorial(int n)->int;

inline auto maximum(int a, int b){
    return a > b ? a : b;
}

auto minimum(auto a, auto b){
    return a < b ? a : b;
}

constexpr int mocnina(int x){
    return x * x;
}

consteval int plus(int a, int b){
    return a + b;
}

template<typename T1, typename T2>
auto __cdcel minimum(T1 a, T2 b){
    T1 x = a;
    return a < b ? a : b;
}


int main(){
    const int N = 4;
    int A[mocnina(N)];
    auto x = maximum(9, 44);
    auto y = minimum(4.5, 8.7);
    auto z = minimum(0L, 5L);
    vypis(1,1,1);
}

static int faktorial(int n){
    return 1;
}