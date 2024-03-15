#include <iostream>
#include <cmath>
#include "go.h"

using std::cout;
using std::endl;

Go::Go(int c)
    :color(c)
{
    cout << "Go constructor\n";
}

// void Go::draw() const{
//     cout << "Go, color " << color << endl;
// }

Point::Point(int x0, int y0, int c)
    : Go(c), x(x0), y(y0)
{
    cout << "Point constructor\n";
}

void Point::draw() const{
    cout << "Point [" << x << ", " << y 
        << "], color " << color << endl;
}

LineSegment::LineSegment(int ax, int ay, int bx, 
                                    int by, int c)
    :Go(c), a(ax, ay, c), b(bx, by, c)
{
    cout << "LineSegment constructor\n";
}

void LineSegment::draw() const{
    cout << "Line segment from ";
    a.draw();
    cout << "to ";
    b.draw();
}

float LineSegment::lenght() const{
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}