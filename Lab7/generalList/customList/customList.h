#ifndef CUSTOMLIST_H
#define CUSTOMLIST_H

template <class T>
class customList
{
private:
    T *arr;
    unsigned int capacity;
    unsigned int index;

public:
    customList();
    customList(unsigned int cap);
    customList(const customList<T> &other);
    ~customList();

    unsigned int getLength() const;
    void push(T value);
    T pop();
    T get(unsigned int index) const;

    customList<T> &operator=(const customList<T> &other);
    customList<T> operator+(const customList<T> &other) const;
    bool operator==(const customList<T> &other) const;

private:
    void resize(unsigned int new_capacity);
};

//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------

#include <stdexcept>

template <class T>
customList<T>::customList()
{
    capacity = 16;
    index = 0;
    arr = new T[capacity];
}

template <class T>
customList<T>::customList(unsigned int cap)
{
    capacity = cap;
    index = 0;
    arr = new T[capacity];
}

template <class T>
customList<T>::customList(const customList<T> &list)
{
    capacity = list.capacity;
    index = list.index;
    arr = new T[capacity];
    for (unsigned int i = 0; i < index; ++i)
    {
        arr[i] = list.arr[i];
    }
}

template <class T>
customList<T>::~customList()
{
    delete[] arr;
}

template <class T>
unsigned int customList<T>::getLength() const
{
    return index;
}

template <class T>
void customList<T>::push(T value)
{
    if (index == capacity)
    {
        resize(capacity * 2);
    }
    arr[index] = value;
    ++index;
}

template <class T>
T customList<T>::pop()
{
    if (index > 0)
    {
        return arr[index--];
    }
    else
    {
        throw "Error: List is empty!";
    }
}

template <class T>
T customList<T>::get(unsigned int index) const
{
    if (index < index)
    {
        return arr[index];
    }
    else
    {
        throw "Error: Index out of bounds!";
    }
}

template <class T>
customList<T> &customList<T>::operator=(const customList &list)
{
    if (this != &list)
    {
        delete[] arr;
        capacity = list.capacity;
        index = list.index;
        arr = new int[capacity];
        for (unsigned int i = 0; i < index; ++i)
        {
            arr[i] = list.arr[i];
        }
    }
    return *this;
}

template <class T>
customList<T> customList<T>::operator+(const customList<T> &list) const
{
    customList result(index + list.index);
    for (unsigned int i = 0; i < index; ++i)
    {
        result.push(arr[i]);
    }
    for (unsigned int i = 0; i < list.index; ++i)
    {
        result.push(list.arr[i]);
    }
    return result;
}

template <class T>
bool customList<T>::operator==(const customList<T> &list) const
{
    if (index != list.index)
    {
        return false;
    }
    for (unsigned int i = 0; i < index; ++i)
    {
        if (arr[i] != list.arr[i])
        {
            return false;
        }
    }
    return true;
}

template <class T>
void customList<T>::resize(unsigned int new_capacity)
{
    T *new_arr = new T[new_capacity];
    for (unsigned int i = 0; i < index; ++i)
    {
        new_arr[i] = arr[i];
    }
    delete[] arr;
    arr = new_arr;
    capacity = new_capacity;
}

#endif
