#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <sstream>

using namespace std;

typedef bool (*comparator)(string& s1, string& s2);

const char* help = R"(SORT - program for sorting files
Using: SORT [parametr] < [input file] > [output file]
Possible parametrs:
-n or /n sorting by number in the beginning of the line
-l or /l lexicographical sorting
)";

//kontrola napovedy

bool lexicographical_comparator(string& s1, string& s2)
{
    return s1 < s2;
}

bool numerical_comparator(string& s1, string& s2)
{
    istringstream input1(s1);
    istringstream input2(s2);
    int n1, n2;
    input1 >> n1;
    input2 >> n2;
    return n1 < n2;
}

void print_help()
{
    //system("CHCP 1250 > NUL");
    cerr << help << endl;
    //system("CHCP 852 > NUL");
    exit(1);
}

//analyza prikazove radky

comparator analysis_of_command_line (int argc, char* argv[])
{
    if(argc != 2)
    {
        print_help();
    }
    if((argv[1][0] != '/') && (argv[1][0] != '-'))
    {
        print_help();
    }
    switch (argv[1][1])
    {
    case 'n':
        return numerical_comparator;
    case 'l':
        return lexicographical_comparator;
    default:
        print_help();
    }
}


int main (int argc, char* argv[])
{
    auto comp = analysis_of_command_line(argc, argv);
    string line;
    vector<string> data; //vytvori prazdny vector
    while(getline(cin, line))
    {
        data.push_back(line);
    }
    sort(data.begin(), data.end(), comp); // iterator ukazujici na prvni prvek, a iterator ukazujici za posledni prvek
    for(auto s: data)
    {
        cout << s << endl;
    } 
}



