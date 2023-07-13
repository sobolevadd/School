#ifndef __TYP_H__
#define __TYP_H__
#include <string>
using namespace std;
typedef string T;  
static const T NULA = "";
typedef bool (*komparator)(void* p1, void* p2);
bool mensi(void* p1, void* p2);
bool mensiDleCisel(void* p1, void* p2);
#endif