// uloha na zjisteni kapacity zasobnika

#include <iostream>

using namespace std;

void test()
{
    int t[256]; //jeden kilobajt
    static int counter = 0;
    cout << counter++ << endl;
    test();
}

int main()
{
    cout << sizeof(int) << endl;
    test();
    return 0;
}


// void test()
// {
//     test();
// } 
// dojde k preteceni zasobniku



// void test()
// {
//     static int counter = 0;
//     cout << counter++ << endl;
//     test();
// }

// int main()
// {
//     test();
//     cout << "Hello wrold!" << endl;
//     return 0;
// }
// kapacita meho zasobniku 1397637 :))