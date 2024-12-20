#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "customGraphics.h"

class Rectangle
{
private:
    Point ul;
    Point lr;

public:
    Rectangle(int x1, int y1, int x2, int y2) : ul(x1, y1), lr(x2, y2) {}

    void draw(Graphics &g)
    {
        int x1 = ul.getX();
        int y1 = ul.getY();
        int x2 = lr.getX();
        int y2 = lr.getY();

        g.line(x1, y1, x2, y1);
        g.line(x2, y1, x2, y2);
        g.line(x2, y2, x1, y2);
        g.line(x1, y2, x1, y1);
    }
};

#endif
