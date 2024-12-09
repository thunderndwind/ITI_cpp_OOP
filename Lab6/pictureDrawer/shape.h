#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
private:
    Color color;

public:
    Shape() {}
    Shape(Color color) : color(color) {}

    void setColor(Color color)
    {
        this->color = color;
    }
    Color getColor()
    {
        return this->color;
    }

    virtual void draw(Graphics &g)
    {
        printf("accessed\n");
    }
};

#endif