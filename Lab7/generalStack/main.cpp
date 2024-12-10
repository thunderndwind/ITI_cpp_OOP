#include <iostream>
#include "generalStack.h"
using namespace std;

int main()
{
    try
    {
        Stack<int> intStack;
        intStack.peek();
        intStack.push(10);
        intStack.push(20);
        intStack.push(30);

        cout << "Top element (peek): " << intStack.peek() << endl;

        cout << "Popped value: " << intStack.pop() << endl;
        cout << "Popped value: " << intStack.pop() << endl;

        cout << "Stack size: " << intStack.size() << endl;

        cout << "Is stack empty? " << (intStack.isEmpty() ? "Yes" : "No") << endl;

        Stack<string> stringStack;
        stringStack.push("Hello");
        stringStack.push("World");

        cout << "Top element (peek): " << stringStack.peek() << endl;

        cout << "Popped value: " << stringStack.pop() << endl;
        cout << "Popped value: " << stringStack.pop() << endl;

        cout << "Is stack empty? " << (stringStack.isEmpty() ? "Yes" : "No") << endl;

        Stack<int> anotherStack;
        anotherStack.push(10);
        anotherStack.push(20);
        cout << "Stacks are equal: " << (intStack == anotherStack ? "Yes" : "No") << endl;
    }
    catch (const char *e)
    {
        cerr << e << endl;
    }

    return 0;
}
