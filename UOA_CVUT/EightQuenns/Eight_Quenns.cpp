#include <iostream>
using namespace std;

enum{OK};

// #define N 8
const int N = 8;

int a [N + 1];

int cnt = 0;

void Play (int s) 
{
    for (int r = 1; r <= N; r++)
    {
        bool ok = true;

        for (int v = 1; v < s&& ok; v++) 
        {
            if (a[s-v] == r || a[s-v] == r-v || a[s-v] == r+v) 
            {
                ok = false;
            }
        }

        if (ok)
        {
            a[s] = r;

            if (s < N)
            {
                Play(s + 1);
            }
            else

            {
                cnt++;
                for (int i = 1; i <= N; i++)
                    cout << a[i] << " ";
                cout << " cnt = " << cnt << endl;

                for (int i = 1; i <= N; i++) //radky
                {
                    for (int k = 1; k <= N; k++) // sloupce
                    {
                        if (a[k] == i)
                            cout << "*";
                        else
                            cout << ".";
                        cout << " ";
                    }
                    cout << endl;
                }
               cout << endl;
            }
        }
    }
}

int main()
{
    for (int i = 0; i <= N; i++)
        a[i] = 0;

    Play (1);

    return OK;
}


