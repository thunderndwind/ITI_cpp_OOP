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
    Color defaultColor;

public:
    Picture(Color defaultColor = Color::RED)
        : cNum(0), rNum(0), lNum(0), pCircles(nullptr), pRects(nullptr), pLines(nullptr), defaultColor(defaultColor)
    {
    }

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
            g.setColor(defaultColor);
            pCircles[i].draw(g);
        }
        for (int i = 0; i < rNum; i++)
        {
            g.setColor(defaultColor);
            pRects[i].draw(g);
        }
        for (int i = 0; i < lNum; i++)
        {
            g.setColor(defaultColor);
            pLines[i].draw(g);
        }
    }
};

#endif
