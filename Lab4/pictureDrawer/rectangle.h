#ifndef RECATNGLE_H
#define RECATNGLE_H
#include "point.h"
#include "graphics.h"

class Rectangle
{
private:
    Point ul;
    Point lr;

public:
    Rectangle(int x1, int y1, int x2, int y2) : ul(x1, y1), lr(x2, y2) {}

    void draw()
    {
        rectangle(ul.getX(), ul.getY(), lr.getX(), lr.getY());
    }
};

#endif