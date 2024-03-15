#include <iostream>
using namespace std;

const int N = 8;

int a[N + 1][N + 1]; // pole vzdalenosti

int zx[N + 1][N + 1]; // pole vzdalenosti
int zy[N + 1][N + 1]; // pole vzdalenosti

// x-ty sloupec (1..N)
// y-ta radka (1..N)
// a[x][y] 
void skoc(int x, int y, int cnt = 0, int x0 = -1, int y0 = -1)
{
    if (x >= 1 && x <= N && y >= 1 && y <= N) {
        if (a[x][y] == -1 || a[x][y] > cnt)
        {
            a[x][y] = cnt;

            zx[x][y] = x0; // na [x][y] prichazime z x0
            zy[x][y] = y0; // z y0

            skoc(x + 2, y + 1, cnt + 1, x, y);
            skoc(x + 2, y - 1, cnt + 1, x, y);
            skoc(x - 2, y + 1, cnt + 1, x, y);
            skoc(x - 2, y - 1, cnt + 1, x, y);

            skoc(x + 1, y + 2, cnt + 1, x, y);
            skoc(x + 1, y - 2, cnt + 1, x, y);
            skoc(x - 1, y + 2, cnt + 1, x, y);
            skoc(x - 1, y - 2, cnt + 1, x, y);
        }
    }
    
}

void my_print()
{
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (a[i][j] == -2)
                cout << "x" << " ";
            else if (a[i][j] == -1)
                cout << "." << " ";
            else
               cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void hledej(int x, int y)
{
    if (x > 0 && y > 0)
    {
        hledej (zx[x][y], zy[x][y]);
        cout << x << ", " << y << endl;
    }
}

int main()
{
    for (int i = 0; i <= N; i++)
        for (int k = 0; k <= N; k++)
            a[i][k] = -1; // nenavstivene pole


    for (int i = 3; i <= 6; i++)
    {
        a[i][2] = -2;
        a[i][7] = -2;
    }

    for (int k = 2; k <= N - 1; k++)
        {
            a[2][k] = -2; // zakazane misto
            a[7][k] = -2; // zakazane misto
        }

    // skoc (1, 1);
    skoc(3, 5); // vychozi pozice
    my_print();

    hledej(7, 8);

    cout << "O.K." << endl;
}

