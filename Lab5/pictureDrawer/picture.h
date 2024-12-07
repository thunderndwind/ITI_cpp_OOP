#ifndef PICTURE_H
#define PICTURE_H

#include "circle.h"
#include "rectangle.h"
#include "line.h"
#include "customGraphics.h"

class Picture
{
private:
    int cNum, rNum, lNum;
    Circle *pCircles;
    Rectangle *pRects;
    Line *pLines;

public:
    Picture() : cNum(0), rNum(0), lNum(0), pCircles(nullptr), pRects(nullptr), pLines(nullptr) {}

    void setCircles(int cn, Circle *pC)
    {
        cNum = cn;
        pCircles = pC;
    }

    void setRects(int rn, Rectangle *pR)
    {
        rNum = rn;
        pRects = pR;
    }

    void setLines(int ln, Line *pL)
    {
        lNum = ln;
        pLines = pL;
    }

    void paint(Graphics &g)
    {
        for (int i = 0; i < cNum; i++)
        {
            pCircles[i].draw(g);
        }
        for (int i = 0; i < rNum; i++)
        {
            pRects[i].draw(g);
        }
        for (int i = 0; i < lNum; i++)
        {
            pLines[i].draw(g);
        }
    }
};

#endif
