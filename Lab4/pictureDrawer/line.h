#ifndef LINE_H
#define LINE_H

#include "customGraphics.h"
#include "point.h"

class Line
{

public:
    Point start;
    Point end;

public:
    Line(int x1, int y1, int x2, int y2) : start(x1, y1), end(x2, y2) {}

    void draw(Graphics &g)
    {
        g.line(start.getX(), start.getY(), end.getX(), end.getY());
    }
};

#endif
