/*
Promenna - musime zadat typ a jmeno (identificator) je mozny do toho ulozit hodnotu. 
        je to pojmenovany blok pameti.

int - se znamenkem
unsigned int - bez znamenka

posloupnost of bytes 
int a;
a=1;
vytvorime promennou,  v pameti se zarezervuje misto v pameti; muzeme zapisovat a cist tu hodnotu.

UKAZATEL/POINTER
    - je promenna, ktera obsahuje adresu (ne data)

    deklaruje se:
    int *pa, *pb;       - normalni promenna s *
    - operator na ziskani adresu apersant(muzwe byt pouze napravo):
    pa = &a;                          // do ukazatele pa ukladam promennou a
    *pa = 5;                          //skoc na ukazatel a zapis tam hodnotu
    nullptr                           //ukazatel nikam, 

    if (pa == nullptr)  <=> if(!pa)   //neni pa
    if (pa != nullptr)  <=> if (pa)   //zapsat pa

    void pointer, do neho muzem ulozit jakykoli jiny ukazatel, nejtypyctejsi ve funkcich ktere nic nevraci

    Ukazatelova aritmetika:
    pa < pb // jsou ukazatele na stejny typ // ukazuje na nizsi adresu
    pa + k //posune se o k*velikost typu v pameti, muzeme vyuzit kdyz chceme projit pole
        const int N = 10;
        int array [N];

        for (int *ptr = &array[0]; ptr < & array [N]; ptr ++) 
                                    //int *ptr = &array[0] <=> int *ptr = array (ukazuje na zacatek)
        {
            *ptr = 0;
        }                           //projde to prvek po prvku a vsechny nastavi na nulu





*/