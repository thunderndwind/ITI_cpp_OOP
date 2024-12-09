#ifndef PICTURE_H
#define PICTURE_H

#include "circle.h"
#include "shape.h"
#include "rectangle.h"
#include "line.h"
#include "customGraphics.h"

class Picture
{
private:
    unsigned int currentIndex = 0;
    int size;
    Shape **pShapes;

public:
    Picture(int size)
    {
        pShapes = new Shape *[size];
        currentIndex = -1;
        this->size = size;
    }

    void addShape(Shape *pS)
    {
        if (currentIndex == size - 1)
        {
            return;
        }
        currentIndex++;
        pShapes[currentIndex] = pS;
    }

    void paint(Graphics &g)
    {
        for (int i = 0; i <= currentIndex; i++)
        {
            pShapes[i]->draw(g);
        }
    }
};

#endif