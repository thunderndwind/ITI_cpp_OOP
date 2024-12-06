#ifndef POINT_H
#define POINT_H

class Point
{
private:
    int x, y;

public:
    Point(int x1, int y1) : x(x1), y(y1) {}

    int getX() const { return x; }
    int getY() const { return y; }
};

#endif