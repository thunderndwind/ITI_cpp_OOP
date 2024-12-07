#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "customGraphics.h"
#include "shape.h"

class Rectangle : public Shape
{
private:
    int x1, y1, x2, y2;

public:
    Rectangle(int x1, int y1, int x2, int y2, Color color)
        : x1(x1), y1(y1), x2(x2), y2(y2), Shape(color) {}

    void draw(Graphics &g)
    {
        g.setColor(color);
        g.line(x1, y1, x2, y1);
        g.line(x2, y1, x2, y2);
        g.line(x2, y2, x1, y2);
        g.line(x1, y2, x1, y1);
    }
};

#endif
