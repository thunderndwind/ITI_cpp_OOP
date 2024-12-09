#include <iostream>

using namespace std;

class GeoShape
{
protected:
    float dim1;
    float dim2;

public:
    GeoShape(float dim1, float dim2)
    {
        this->dim1 = dim1;
        this->dim2 = dim2;
    }
    void setDim1(float dim1)
    {
        this->dim1 = dim1;
    }
    void setDim2(float dim2)
    {
        this->dim1 = dim1;
    }
    float getDim1()
    {
        return dim1;
    }
    float getDim2()
    {
        return dim2;
    }
    virtual float calculateArea() = 0;
};
class Triangle : public GeoShape
{

public:
    Triangle(float dim1, float dim2) : GeoShape(dim1, dim2)
    {
    }
    float calculateArea()
    {
        return 0.5 * dim1 * dim2;
    }
};

class Rectangle : protected GeoShape
{
public:
    Rectangle(float dim1, float dim2) : GeoShape(dim1, dim2)
    {
    }
    void set_x(float dim1)
    {
        GeoShape::setDim1(dim1);
    }
    void set_y(float dim2)
    {
        GeoShape::setDim2(dim2);
    }
    float get_x()
    {
        return GeoShape::getDim1();
    }
    float get_y()
    {
        return GeoShape::getDim2();
    }
    float calculateArea()
    {
        return dim1 * dim2;
    }
};

class Circle : private GeoShape
{

public:
    Circle(float radius) : GeoShape(radius, radius)
    {
    }
    void setRadius(float radius)
    {
        dim1 = radius;
        dim2 = radius;
    }
    float getRadius()
    {
        return dim1;
    }
    float calculateArea()
    {
        return 22.0 / 7 * dim1 * dim2;
    }
};

class Square : private Rectangle
{
public:
    Square(float dim1) : Rectangle(dim1, dim1)
    {
    }
    void setSquareDim(float dim1)
    {
        this->dim1 = dim1;
        this->dim2 = dim1;
    }
    float getSquareDim()
    {
        return dim1;
    }
    float calculateArea()
    {
        return Rectangle::calculateArea();
    }
};

int main()
{
    Rectangle rectangle(3, 4);
    cout << "recatngle area: " << rectangle.calculateArea() << endl;

    Square square(10);
    cout << "square area: " << square.calculateArea() << endl;

    Triangle triangle(3, 4);
    cout << "recatngle area: " << triangle.calculateArea() << endl;

    Circle c(10);
    cout << "circle area: " << c.calculateArea() << endl;

    return 0;
}