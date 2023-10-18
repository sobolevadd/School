#ifndef POINT_HPP
#define POINT_HPP

// struct Point
// {
//     float x, y;
// };

// class Point
// {
//     public:
//     float x, y;
// };

class Point
{
    float x, y;
public:
    Point();
    Point(float, float);
    ~Point();
    float getX() const
    {
        return this->x;
    }
    void setX(const float val) 
    {
        this->x = val;
    }

    float getY() const
    {
        return y;
    }
    void setY(const float val) 
    {
        y = val;
    }

    void print() const;
    float distance(Point &other) const;
};

void print(Point &);
float distance(Point &, Point &);

#endif //POINT_HPP