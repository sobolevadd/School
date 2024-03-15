#ifndef __PRVEK_H__
#define __PRVEK_H__

#include "Typ.h"
class Prvek
{
	T data;
	Prvek* dalsi;
public:
	Prvek();
	Prvek(T _data, Prvek* _dalsi);
	T getData();
	void setData(T _data);
	Prvek *getDalsi();
	void setDalsi(Prvek* _dalsi);
    void set(T _data, Prvek* _dalsi);
};
#endif