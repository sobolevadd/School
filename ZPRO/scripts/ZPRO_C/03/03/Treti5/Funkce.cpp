// SOUBOR OBSAHUJ�C� POUZE FUNKCI fakt()
// A PROM�NNOU zadano


/* Funkce fakt vypo�te faktori�l cel�ho ��sla n.
 * n mus� b�t nez�porn� cel� ��slo
 * men�� ne� 13
 * Pro z�porn� n vrac� 1
 */

int fakt(int n)                   // Hlavi�ka funkce
{
  int vysledek = 1,                    // Deklarace lok�ln�ch prom�nn�ch
  i = 1;
  while(i < n+1) 
  {
    vysledek *= i++;
  }
  return vysledek;                     // Zde ur�ujeme, co je v�sledkem funkce
}    

int zadano;                         // Obsahuje vstup od u�ivatele
