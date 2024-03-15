#ifndef __LIST_H__
#define __LIST_H__

#include <iostream>

using T = int;

//typedef int T

const T NULA = 0;

struct element
{
    T data;
    element* next;
};

struct list
{
    element* head;
    element* sentinel;
    size_t length;
};

void CreateList(list& s);
void Push_front(list& s, T what);
void Push_back(list& s, T what);
void Pop_first(list& s );

#endif __LIST_H__