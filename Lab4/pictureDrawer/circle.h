#ifndef CIRCLE_H
#define CIRCLE_H

#include "customGraphics.h"
#include "point.h"

class Circle
{
private:
    Point center;
    int radius;

public:
    Circle(int x, int y, int radius)
        : center(x, y), radius(radius) {}

    void draw(Graphics &g)
    {
        int dx = radius - 1;
        int dy = 0;
        int err = dx - (radius << 1);
        int x = center.getX();
        int y = center.getY();

        while (dx >= dy)
        {
            g.putpixel(x + dx, y - dy);
            g.putpixel(x + dx, y + dy);
            g.putpixel(x - dx, y - dy);
            g.putpixel(x - dx, y + dy);
            g.putpixel(x + dy, y - dx);
            g.putpixel(x + dy, y + dx);
            g.putpixel(x - dy, y - dx);
            g.putpixel(x - dy, y + dx);

            if (err <= 0)
            {
                ++dy;
                err += (dy << 1) + 1;
            }
            if (err > 0)
            {
                --dx;
                err -= (dx << 1) + 1;
            }
        }
    }
};

#endif
