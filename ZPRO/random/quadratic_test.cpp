#include <iostream>
#include <math.h>

using namespace std;

enum struct Type { Real, Complex};
enum { a1, b1, c1, x1 = 0, x2};

struct Result
{
    Type type;
    double result[2];
};

Result quadratic(double koeficient[1])
{
    Result result;
    double a  = koeficient[a1];
    double b = koeficient[b1];
    double c = koeficient[c1];
    double d = b * b - 4 * a * c;
    if (d >= 0){
        d = sqrt(d);
        result.type = Type::Real;
        result.result[0] = -b + d / 2 * a;
        result.result[1] = -b - d / 2 * a;   
    }else
    {
        d = sqrt(-d);
        result.type = Type::Complex;
        result.result[0] = -b / 2 * a;
        result.result[1] = d / 2 / a;
    } 
    return result;
}

int main()
{
    double koeficient[3]{};
    cout << "Zadej a, b, c: ";
    cin >> koeficient[a1] >> koeficient[b1] >> koeficient[c1];
    Result result = quadratic(koeficient);
    if (result.type == Type::Real)
    {
        cout << "x1 = "<< result.result[0] << ", x2 = " << result.result[1] << endl;
    }else 
    {
        cout << "x1,2 = " << result.result[0] << " +- i*" << result.result[1] << endl; 
    }
    return 0;
}