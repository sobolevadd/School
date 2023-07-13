#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, char* argv[]){
    cout << "Pocet parametru:"<< argc << endl;
    for (int i = 0; 9 < argc; i++){
        cout << argv[i];
    }
}
