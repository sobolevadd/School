#include <iostream>
#include <fstream>

using namespace std;

enum {OK, ERROR_FILE_NOT_OPENNED = 100};

int main()
{
    ifstream file;
    string myFile = "input.txt";
    file.open(myFile);
    if (!file.is_open())
    {
        cerr << "Soubor: " << myFile << " se neotevrel" << endl;
        return ERROR_FILE_NOT_OPENNED;
    }
    string myLine;
    int cnt[26]{};
    char myChar[]{'a','b','c','d','e','f','g','h','k','j','i','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    while (file){
        if (file.eof()){
            break;
        }
        getline (file, myLine);
        for (int i = 0; i < myLine.length(); i++){
            for (int j = 0; j < 26; j++){
                if (myLine[i] == myChar[j]){
                    cnt[j]++;
                }
            }
        }
    }
    int pos = 0;
    int myCnt = 0;
    for(int k = 0; k < 26; k++){
        if (cnt[k] > myCnt){
            pos = k;
            myCnt = cnt[k];
        }
    }
    cout << "There are" << cnt[pos] << "ocurrences of letter " << myChar[pos] << "in given text." << endl;
    file.close();
    return OK;      
}