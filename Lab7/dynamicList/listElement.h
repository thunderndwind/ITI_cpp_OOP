#ifndef ELEMENT_H
#define ELEMENT_H

template <class T>
class Element
{
    char *type;
    T value;
};

class VoidElement
{
    char *type;
    void *value;
};
#endif