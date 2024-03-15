#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

using u_comperator = bool(*)(string&, string&);

bool lex_comperator(string& s1, string& s2){
    return s1 < s2;
}

const char *text_help = L"(Fillter SORT for sorting contents of text files
USAGE:
SORT2 [choice] < [input_file] > [output_file],
where [choice] is
-n  for sorting according to the value of the numbers on the initial case
-1  for lexicographic sorting.
You need to choose only 1 choice.
)";


void help(){
    //system("CHCP 1250 > NUL"); pro cestinu
    cout << text_help << endl;
    exit(0);
}

u_comperator process_parametrs (int argc, char* argv[]){
    if(argc != 2 || argv[1][0] != '-'){
        help();
    }
    if(argv[1][1] == '1'){
        return lex_comperator;
    }else{
        help();
    }
}

int main(int argc, char* argv[]){
    string line; 
    vector<string> input_data;
    while(getline(cin, line)){
        input_data.push_back(line);
    }
    sort(input_data.begin(), input_data.end(), lex_comperator);
    for (string l : input_data){
        cout << l << endl;
    }
    return 0;
}