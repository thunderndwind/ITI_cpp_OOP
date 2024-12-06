#ifndef CIRCLE_H
#define CIRCLE_H
#include "point.h"
#include "graphics.h"

class Circle
{
private:
    Point center;
    int radius;

public:
    Circle(int m, int n, int r) : center(m, n), radius(r) {}

    void draw()
    {
        circle(center.getX(), center.getY(), radius);
    }
};

#endif