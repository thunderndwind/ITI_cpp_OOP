#ifndef LINE_H
#define LINE_H

#include "customGraphics.h"
#include "shape.h"

class Line : public Shape
{
private:
    int x1, y1, x2, y2;

public:
    Line(int x1, int y1, int x2, int y2, Color color)
        : x1(x1), y1(y1), x2(x2), y2(y2), Shape(color) {}

    void draw(Graphics &g)
    {
        g.setColor(getColor());
        g.line(x1, y1, x2, y2);
    }
};

#endif
