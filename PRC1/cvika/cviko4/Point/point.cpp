#include <iostream>
#include <cmath>
#include "point.hpp"

Point::Point()
{
    setX(0);
    setY(0);
    std::cout << "Constructor without parametrs\n";
}

Point::Point(float x0, float y0)
    :x(x0), y(y0)
{
    std::cout << "Constructor with two parametrs\n";
}

Point::~Point()
{
    std::cout << "Destructor\n";
}

void Point::print() const
{
    std::cout << "[" << this->getX() << ", " << this->getY() << "]\n" ;
}

void print(Point &p)
{
    p.print();
    //cout << "[" << p.getX() << ", " << p.getY() << "]\n" ;
}

float Point::distance(Point &other) const
{
    float dx = this->getX() - other.getX();
    float dy = this->getY() - other.getY();
    return sqrt(pow(dx, 2)+ pow(dy, 2));
    //return sqrt(pow(this->x + other.x, 2) + pow(this->y + other.y,2));
}

float distance(Point &a, Point &b)
{
    return a.distance(b);
}