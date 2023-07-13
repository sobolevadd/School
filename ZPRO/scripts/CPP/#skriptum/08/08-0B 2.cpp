// Soubor 08-0B.CPP
// Priklad na pole a ukazatele

const int N = 10;

int P[N], Q[N];   // jednorozmerne pole

int main()
{
 // vyplnime pole P cisly:
 for(int i = 0; i < N; i++)
   P[i] = i;	// Takhle to zname z Pascalu;


 // Muzeme ale take pouzit ukazatelu a adresove aritmetiky.
 // Vyplnime pole Q jednickami:
 for(int *ui = Q; ui < &Q[N]; ui++) // i kdyz prvek Q[N] neexistuje,
   *ui = 1;			   // smime pouzit jeho adresu

 // alokujeme dynamicke pole o delce N:
 int *u = new int [N];

 // vyplnime ho cisly 100 - 100+N-1:
 for(i = 0; i < N; i++) u[i] = 100+i;  // ukazatel lze indexovat!

 // nyni prepiseme dynamicke pole obracene:
 for(int *u1 = u, *u2 = u+N-1; u1 < u2; u1++, u2--)
 {
  int a = *u1;
  *u1 = *u2;
  *u2 = a;
 }

 // Nakonec dynamicke pole uvolnime:
 delete u;

 return 0;
}


