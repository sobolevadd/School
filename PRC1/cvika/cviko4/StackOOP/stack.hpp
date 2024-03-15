#ifndef STACK_HPP
#define STACK_HPP  

typedef int Data;

class Stack
{
    int sp;
    int size;
    Data *array;
public:
    Stack(int capacity);
    ~Stack();
    void push(Data d);
    void pop();
    Data top() const;
    
    bool isEmpty() const
    {
    return(sp == -1);
    }

    bool isFull() const
    {
    return(sp == size -1);
    }   

    int getSize() const
    {
        return size;
    }
};


#endif // STACK_HPP