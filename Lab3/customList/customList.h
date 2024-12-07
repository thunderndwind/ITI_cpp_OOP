#ifndef CUSTOMLIST_H
#define CUSTOMLIST_H

class customList
{
private:
    int *arr;
    unsigned int capacity;
    unsigned int length;

public:
    customList();
    customList(unsigned int cap);
    customList(const customList &other);
    ~customList();

    unsigned int getLength() const;
    void push(int value);
    void pop();
    int get(unsigned int index) const;

    customList &operator=(const customList &other);
    customList operator+(const customList &other) const;
    bool operator==(const customList &other) const;

private:
    void resize(unsigned int new_capacity);
};

//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------

// #include <iostream>
using namespace std;

customList::customList()
{
    capacity = 16;
    length = 0;
    arr = new int[capacity];
}

customList::customList(unsigned int cap)
{
    capacity = cap;
    length = 0;
    arr = new int[capacity];
}

customList::customList(const customList &list)
{
    capacity = list.capacity;
    length = list.length;
    arr = new int[capacity];
    for (unsigned int i = 0; i < length; ++i)
    {
        arr[i] = list.arr[i];
    }
}

customList::~customList()
{
    delete[] arr;
}

unsigned int customList::getLength() const
{
    return length;
}

void customList::push(int value)
{
    if (length == capacity)
    {
        resize(capacity * 2);
    }
    arr[length] = value;
    ++length;
}

void customList::pop()
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

int customList::get(unsigned int index) const
{
    if (index < length)
    {
        return arr[index];
    }
    else
    {
        cout << "Error: Index out of bounds!" << endl;
        return -1; // Return a default error value (not used in normal cases)
    }
}

customList &customList::operator=(const customList &list)
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

customList customList::operator+(const customList &list) const
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

bool customList::operator==(const customList &list) const
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

void customList::resize(unsigned int new_capacity)
{
    int *new_arr = new int[new_capacity];
    for (unsigned int i = 0; i < length; ++i)
    {
        new_arr[i] = arr[i];
    }
    delete[] arr;
    arr = new_arr;
    capacity = new_capacity;
}

#endif
