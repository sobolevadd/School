#ifndef GO_H
#define GO_H

//abstract class
class Go
{
protected:
    int color;
public:
    Go(int c);
    int getColor() const {return color;}
    void setColor(int c) {color = c;}
    //pure virtual method
    virtual void draw() const = 0;
};

class Point : public Go{
protected:
    int x, y;
public:
    Point(int x0, int y0, int c);
    virtual ~Point(){}
    int getX() const {return x;}
    int getY() const {return y;}
    void setX(int val) {x = val;}
    void setY(int val) {y = val;} 
    virtual void draw() const;
    friend class LineSegment;
};

// Is a relation -> inheritence
class LineSegment : public Go{
protected:
    Point a, b; //Has a relation -> composition
public:
    LineSegment(int ax, int ay, int bx, int by, int c);
    //LineSegment(Point a0, Point b0, int c);
    virtual ~LineSegment(){}
    void setA(Point p) {a = p;}
    void setB(Point p) {b = p;}
    Point getA() const {return a;}
    Point getB() const {return b;}
    // get/set ax, ay, bx, by
    virtual void draw() const;
    float lenght() const;
};

#endif // GO_H