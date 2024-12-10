#ifndef STACK_H
#define STACK_H

#include <stdexcept>

template <class T>
class Stack
{
private:
    T *arr;
    unsigned int capacity;
    unsigned int index;

public:
    Stack();
    Stack(unsigned int cap);
    Stack(const Stack<T> &other);
    ~Stack();

    unsigned int size() const;
    void push(T value);
    T pop();
    T peek() const;
    bool isEmpty() const;

    Stack<T> &operator=(const Stack<T> &other);
    bool operator==(const Stack<T> &other) const;

private:
    void resize(unsigned int new_capacity);
};

//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------

template <class T>
Stack<T>::Stack()
{
    capacity = 16;
    index = 0;
    arr = new T[capacity];
}

template <class T>
Stack<T>::Stack(unsigned int cap)
{
    capacity = cap;
    index = 0;
    arr = new T[capacity];
}

template <class T>
Stack<T>::Stack(const Stack<T> &other)
{
    capacity = other.capacity;
    index = other.index;
    arr = new T[capacity];
    for (unsigned int i = 0; i < index; ++i)
    {
        arr[i] = other.arr[i];
    }
}

template <class T>
Stack<T>::~Stack()
{
    delete[] arr;
}

template <class T>
unsigned int Stack<T>::size() const
{
    return index;
}

template <class T>
void Stack<T>::push(T value)
{
    if (index == capacity)
    {
        resize(capacity * 2);
    }
    arr[index] = value;
    ++index;
}

template <class T>
T Stack<T>::pop()
{
    if (index > 0)
    {
        --index;
        return arr[index];
    }
    else
    {
        throw "Error: Stack is empty!";
    }
}

template <class T>
T Stack<T>::peek() const
{
    if (index > 0)
    {
        return arr[index - 1];
    }
    else
    {
        throw "Error: Stack is empty!";
    }
}

template <class T>
bool Stack<T>::isEmpty() const
{
    return index == 0;
}

template <class T>
Stack<T> &Stack<T>::operator=(const Stack<T> &other)
{
    if (this != &other)
    {
        delete[] arr;
        capacity = other.capacity;
        index = other.index;
        arr = new T[capacity];
        for (unsigned int i = 0; i < index; ++i)
        {
            arr[i] = other.arr[i];
        }
    }
    return *this;
}

template <class T>
bool Stack<T>::operator==(const Stack<T> &other) const
{
    if (index != other.index)
    {
        return false;
    }
    for (unsigned int i = 0; i < index; ++i)
    {
        if (arr[i] != other.arr[i])
        {
            return false;
        }
    }
    return true;
}

template <class T>
void Stack<T>::resize(unsigned int new_capacity)
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
