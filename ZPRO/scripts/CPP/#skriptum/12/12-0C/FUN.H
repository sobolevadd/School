/* Soubor 12-0C\FUN.H
 hlavickovy soubor spolecny pro C a C++
*/

#ifdef __cplusplus
extern "C" {   // tato cast se preklada pouze v programech v C++
#endif

void F(void);      // tato cast deklarace je spolecna pro oba jazyky

#ifdef __cplusplus
}              // a tato cast je zase jen pro C++
#endif

