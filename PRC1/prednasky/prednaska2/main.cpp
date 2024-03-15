#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <sstream>

using namespace std;


const char* help = R"aa(SORT - program for sorting files
Using: SORT [parametr] < [input file] > [output file]
Possible parametrs:
-n or /n sorting by number in the beginning of the line
-l or /l lexicographical sorting
)aa";

void print_help()
{
    cerr << help << endl;
    exit(1);
}

int main (int argc, char* argv[])
{
    
    print_help();
    cout << "Hello world!" << endl; // nebude vypsano, protoze byla funkce exit()
}


// #include <iostream>

// enum {OK,ERROR = 100};
// using namespace std;

// int main() {
//     
//     bool b = false;
//     bool c = true;
//     cout << boolalpha << b << " " << noboolalpha << c << endl;
//     char d = 'á';
//     cout << (int)d << endl;
//     //realny 0.1e+-10
//     
//     int y = 1'000;
//     int z = 5e29;
//     double delta = 0.1;
//     double x = 0;
//     while (x != 1.0)
//     {
//         x += delta;
//         cout << x << endl;
//     }
//     return OK;
//     
// }