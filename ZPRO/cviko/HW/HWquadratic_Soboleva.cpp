#include <iostream>
#include <cmath>

using namespace std;

enum struct Type {Real, Complex};
enum { a1 = 1, b1, c1, x1 = 0 , x2,};

struct Result
{
    Type type;
    double result[];
};

Result quadratic(double coefficient[])
{
    double a = coefficient[a1];
    double b = coefficient[b1];
    double c = coefficient[c1];
    double d = b * b - 4 * a * c;
    Result result;
    if (d > 0){
        //d = sqrt(d);
        result.type = Type::Real;
        result.result[0] = -b + sqrt(d) / 2 * a;
        result.result[1] = -b - sqrt(d) / 2 * a;   
    }else if (d == 0){
        //d = sqrt(d);
        result.type = Type::Real;
        result.result[0] = -b / (2 * a);
        result.result[1] = -b / (2 * a);
    }else
    {
        //d = sqrt(-d);
        result.type = Type::Complex;
        result.result[0] = -b / 2 * a;
        result.result[1] = sqrt(-d) / 2 / a;
    } 
    return result;
}



int main(){
    double coefficient[4]{};
    cout << "Enter a, b, c: ";
    cin >> coefficient[a1] >> coefficient[b1] >> coefficient[c1];
    Result result = quadratic(coefficient);
    //cout << "You've choosed quadratic equation:" << 
    //a1 << "*x^2 + " << b1 << "x + " << c1 << " = 0 " << endl;
    cout << "The result of quadratic equation is:" << endl;
    if (result.type == Type::Real)
    {
        cout << "x1 = "<< result.result[0] << ", x2 = " << result.result[1] << endl;
    }else 
    {
        cout << "x1 = " << result.result[0] << " + i*" << result.result[1] << endl; 
        cout << "x2 = " << result.result[0] << " - i*" << result.result[1] << endl;
    }
    return 0;

}

 




