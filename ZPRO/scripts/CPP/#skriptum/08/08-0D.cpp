// Soubor 08-0D.CPP
// adresova aritmetika u dvourozmerneho pole

#include <iostream>
using namespace std;

double mat[3][4] = {
						  {1,2,3,4,},
						  {5,6,7,8,},
						  {9, 10,11,12,},
					};



int main()
{
 // vyplnime sloupec s indexem 1 cislem -5
 double (*uk_radek)[4];              // ukazatel na radek matice, tj. na pole 4 prvku typu double
 for( uk_radek = mat;
		uk_radek < &mat[3];
		uk_radek++)
				  (*uk_radek)[1] = -5;

 // vyplnime matici nulami
 for( uk_radek = mat;                // Vnejsi cyklus podle radku
		uk_radek < &mat[3];
		uk_radek++)
				  for(double* d = *uk_radek;
						d < &(*uk_radek)[4];
						d++)
							*d = 0;
 return 0;
}

// deklarace
// double (*uk_radek)[4];
// znamena, ze uk_radek je ukazatel na pole 4 prvku typu double
// POZOR, zavorka je nezbytna:
// deklarace
// double *uk_radek[4];
// by znamenala pole 4 ukazatelu na double
//
// inicializace cyklu:
// uk_radek = mat;
// Znamena: mat je pole 3 prvku, ale to jsou zase pole (se 4 prvky typu double)
// ALE: pole se automaticky konvertuje na ukazatel na prvni prvek,
// a to je v nasem pripade opet pole (nulty radek matice)
//
// Prikaz
// uk_radek++;
// zpusobi prechod na dalsi prvek pole, ale to znamena na dalsi
// radek matice mat!!!
// Jinymi slovy: na pocatku ukazuje uk_radek na mat[0],
// po uk_radek++ na mat[1] atd.

// Vyraz (*uk_radek)[1]:
// uk_radek je ukazatel na pole, a proto  *uk_radek  znamena pole.
// Lze na nej tedy pouzit operator indexovani. (presneji: konvertuje se
// na ukazatel na prvni prvek a na ten se pouzije [].