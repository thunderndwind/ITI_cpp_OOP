#ifndef SHAPE_H
#define SHAPE_H
#include "customGraphics.h"

class Shape
{
protected:
    Color color;

public:
    Shape(Color color) : color(color) {}
};

#endif