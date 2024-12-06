#include <iostream>
#include <stdexcept>

using namespace std;

void customStrcpy(char *dest, const char *src, short int max)
{
    unsigned int i = 0;
    while (src[i] != '\0' && i < max)
    {
        dest[i] = src[i];
        ++i;
    }
    dest[i] = '\0';
}

class Employee
{
public:
    unsigned int code;
    char name[40];
    unsigned int netSalary;
    Employee()
    {
        code = 0;
        name[0] = '\0';
        netSalary = 0;
    }

    Employee(unsigned int c, const char *n, unsigned int s)
    {
        code = c;
        customStrcpy(name, n, 39);
        name[39] = '\0';
        netSalary = s;
    }

    ~Employee()
    {
    }
};

class Stack
{
private:
    Employee *employees;
    int top;
    int size;

    static int createdStacks;
    static int destroyedStacks;

public:
    Stack(int size)
    {
        this->size = size;
        employees = new Employee[size];
        top = -1;
        createdStacks++;
    }

    Stack(Stack &old)
    {
        this->size = this->size;
        employees = new Employee[size];
        top = -1;
        createdStacks++;
    }

    ~Stack()
    {
        delete[] employees;
        destroyedStacks++;
    }

    void push(Employee emp)
    {
        if (isFull())
        {
            throw runtime_error("Stack is full, cannot add more employees.");
        }
        employees[++top] = emp;
    }

    Employee pop()
    {
        if (isEmpty())
        {
            throw runtime_error("Stack is empty, no employee to pop.");
        }
        return employees[top--];
    }
    void operator=(Stack &old)
    {
    }

    void printStack()
    {
        if (isEmpty())
        {
            cout << "No employees to display." << endl;
            return;
        }
        cout << "Employee List:" << endl;
        for (int i = top; i >= 0; i--)
        {
            cout << "Code: " << employees[i].code << ", Name: " << employees[i].name
                 << ", Net Salary: " << employees[i].netSalary << endl;
        }
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == size - 1;
    }

    bool isUnique(int id)
    {
        for (int i = top; i >= 0; i--)
        {
            if (this->employees[i].code == id)
            {
                return false;
            }
        }
        return true;
    }

    static int getCreatedStacks()
    {
        return createdStacks;
    }

    static int getDestroyedStacks()
    {
        return destroyedStacks;
    }
};

void viewContentByReference(Stack &stack)
{
    cout << "Viewing content by reference:" << endl;
    stack.printStack();
}

void viewContentByValueNoCopy(Stack stack)
{
    cout << "Viewing content by value (no copy constructor):" << endl;
    stack.printStack();
}

void viewContentByValueWithCopy(Stack stack)
{
    cout << "Viewing content by value (with copy constructor):" << endl;
    stack.printStack();
}

int Stack::createdStacks = 0;
int Stack::destroyedStacks = 0;

int main()
{
    Employee emp1(1, "Abdullah", 500000);
    Employee emp2(2, "Elamine", 90000);
    Employee emp3(3, "Zaki", 70000);

    Stack stack(5);
    Stack stack2(1);
    stack.push(emp1);
    stack.push(emp2);
    stack.push(emp3);
    stack2 = stack;

    // Viewing content using different methods
    cout << "main Stack =======\n";
    viewContentByReference(stack);
    viewContentByValueNoCopy(stack);
    // viewContentByValueWithCopy(stack);

    cout << "second Stack =======\n";
    viewContentByReference(stack2);
    viewContentByValueNoCopy(stack2);

    // Stack created and destroyed count
    cout << "Stacks created: " << Stack::getCreatedStacks() << endl;
    cout << "Stacks destroyed: " << Stack::getDestroyedStacks() << endl;

    return 0;
}
