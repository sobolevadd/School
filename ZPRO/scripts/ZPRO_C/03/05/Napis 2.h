// P�t� program: n�pis objektov�
// Hlavi�kov� soubor pro t��du napis

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