#include "Prvek.h"

Prvek::Prvek()
{
	set(NULA, nullptr);
}

Prvek::Prvek(T _data, Prvek * _dalsi)
{
	set(_data, _dalsi);
}

void Prvek::setDalsi(Prvek *_dalsi)
{
	dalsi = _dalsi;
}

void Prvek::setData(T _data)
{
	data = _data;
}

T Prvek::getData()
{
	return data;
}

Prvek* Prvek::getDalsi()
{
	return dalsi;
}

void Prvek::set(T _data, Prvek* _dalsi)
{
	setData(_data);
	setDalsi(_dalsi);
}

