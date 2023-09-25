#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

enum {OK};

int main () {
    string line;
    vector<string> read;
    // cin >> line; precte jenom jednu polozku
    while (getline(cin, line)) {
        read.push_back(line); 
    }
    sort(read.begin(), read.end()); //uz je to serazeny
    //porovnava sse lexikografickz, tj jestli vstup 9, 10, 20, ... bude serazeny jako 10, 20, 9 podle prvniho prvku
    for (auto text : read) // takovy for znamena prober cely kontajner prvek po prvku
    {
        cout << text << endl; //   ./make < input.txt > output.txt     
        // jestli psat cerr (chybovy vystup), vypise se to do terminalu , protoze neni to presmerovany
    }
    return OK;
}