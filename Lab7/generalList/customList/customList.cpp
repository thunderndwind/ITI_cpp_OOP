#include "customList.h"
#include <iostream>
using namespace std;

template <class T>
customList<T>::customList()
{
    capacity = 16;
    length = 0;
    arr = new T[capacity];
}

template <class T>
customList<T>::customList(unsigned int cap)
{
    capacity = cap;
    length = 0;
    arr = new T[capacity];
}

template <class T>
customList<T>::customList(const customList<T> &list)
{
    capacity = list.capacity;
    length = list.length;
    arr = new T[capacity];
    for (unsigned int i = 0; i < length; ++i)
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
    return length;
}

template <class T>
void customList<T>::push(T value)
{
    if (length == capacity)
    {
        resize(capacity * 2);
    }
    arr[length] = value;
    ++length;
}

template <class T>
T customList<T>::pop()
{
    if (length > 0)
    {
        --length;
    }
    else
    {
        cout << "Error: List is empty!" << endl;
    }
}

template <class T>
T customList<T>::get(unsigned int index) const
{
    if (index < length)
    {
        return arr[index];
    }
    else
    {
        cout << "Error: Index out of bounds!" << endl;
        return -1;
    }
}

template <class T>
customList<T> &customList<T>::operator=(const customList &list)
{
    if (this != &list)
    {
        delete[] arr;
        capacity = list.capacity;
        length = list.length;
        arr = new int[capacity];
        for (unsigned int i = 0; i < length; ++i)
        {
            arr[i] = list.arr[i];
        }
    }
    return *this;
}

template <class T>
customList<T> customList<T>::operator+(const customList<T> &list) const
{
    customList result(length + list.length);
    for (unsigned int i = 0; i < length; ++i)
    {
        result.push(arr[i]);
    }
    for (unsigned int i = 0; i < list.length; ++i)
    {
        result.push(list.arr[i]);
    }
    return result;
}

template <class T>
bool customList<T>::operator==(const customList<T> &list) const
{
    if (length != list.length)
    {
        return false;
    }
    for (unsigned int i = 0; i < length; ++i)
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
    for (unsigned int i = 0; i < length; ++i)
    {
        new_arr[i] = arr[i];
    }
    delete[] arr;
    arr = new_arr;
    capacity = new_capacity;
}