#ifndef CALCULATESUM_H
#define CALCULATESUM_H

#include <iostream>
using namespace std;

class Base
{
public:
    virtual void calculateSum(int x, int y)
    {
        cout << "from Base sum" << x + y << endl;
    }
};

class Derived : public Base
{
public:
    void calculateSum(int x, int y)
    {
        cout << "from Derived sum" << x + y << endl;
    }
};

#endif
