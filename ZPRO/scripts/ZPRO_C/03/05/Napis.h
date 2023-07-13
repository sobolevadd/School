// Pátý program: nápis objektovì
// Hlavièkový soubor pro tøídu napis

#ifndef __NAPIS_H__
#define __NAPIS_H__

class napis 
{
    char text[100];
public:
    napis(char zadani[]);
    void nastav(char zadani[]);
    void vypis();
};

#endif