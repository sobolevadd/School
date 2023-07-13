#ifndef PRVEK_H
#define PRVEK_H

#include "typ.h"

struct Prvek
{
    Data data;
    Prvek *dalsi;
};

#endif // PRVEK_H
