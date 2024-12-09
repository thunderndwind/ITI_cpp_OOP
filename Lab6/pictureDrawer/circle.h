#ifndef CIRCLE_H
#define CIRCLE_H

#include "customGraphics.h"
#include "shape.h"

class Circle : public Shape
{
private:
    int x, y, radius;

public:
    Circle(int x, int y, int radius, Color color)
        : x(x), y(y), radius(radius), Shape(color) {}

    void draw(Graphics &g)
    {
        g.setColor(getColor());
        int dx = radius - 1;
        int dy = 0;
        int err = dx - (radius << 1);

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
