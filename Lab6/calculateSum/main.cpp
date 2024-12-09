#include "calculateSum.h"

int main()
{
    Base *b = new Derived();
    b->calculateSum(1, 2);
    delete b;
    return 0;
}
