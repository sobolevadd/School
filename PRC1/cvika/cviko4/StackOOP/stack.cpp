#include "stack.hpp"

Stack::Stack(int capacity)
    :sp(-1), size(capacity), array(new Data[size])
{
    //array = new Data[size];
}

Stack::~Stack()
{
    delete [] array;
}

void Stack::push(Data d)
{
    if(!isFull())
    {
        sp++;
        array[sp] = d;
    } else
    {
        //throw std::logic_error("Pushing into full stack");
    }
}

void Stack::pop() const
{
    if(!isEmpty())
    {
        sp--;
    } else {
        //throw std::logic_error("Popping from empty stack");
    }
}

Data Stack::top( ) const
{
    if(!isEmpty())
    {
        return array[sp];
    } else {
        //throw
    }
}




