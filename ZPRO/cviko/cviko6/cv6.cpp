#include <iostream>

using namespace std;



/*
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

void print_vector (vector<int> vectorr)
{
   for (int i = 0; i < vectorr.size(); i++){
        cout << vectorr[i] << " ";
    }
    cout << "\n";
}

int main(){
    vector<int> vector_1 {2, 3, 4, 5}, vector_2 = { 1, 2, 3, 4};
    cout<<"First Vector Elements:";
    print_vector(vector_1);
    cout << "Second Vector Elements: " << endl;;
    print_vector(vector_2);

    vector<int> vect1(vector_1.size() + vector_2.size());
    merge(
            vector_1.begin(),
            vector_1.end(),
            vector_2.begin(),
            vector_2.end(),
            vect1.begin());
    cout<<"New Vector Elements using: ";
    print_vector(vect1);

    return 0;

}*/

/*
struct output{int index; double value;};

output sfindmax(double x[], int n);

output sfindmax(double x[], int n){
    double maxx = x[0];
    int imax = 0;
    for(int i = 1; i < n; i++){
        if (x[i] > maxx){
            maxx = x[i];
            imax = i;
        }
    }
    imax = imax + 1;
    output v;
    v.index = imax;
    v.value = maxx;
    return v;
}

int main(){
    double x[] = {1.5, 5.1, 9.0,8.5};
    int n = sizeof(x)/sizeof(x[0]);
    output v = sfindmax(x,n);

    cout << "..." << v.index << endl;
    return 0;
}/*/