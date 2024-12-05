#include <iostream>
#include <unistd.h>
#include <termios.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <cctype>
#include <stdexcept>

using namespace std;

// Define keys
#define EXTENDED 27
#define EXTENDED_ARROWS 91
#define LEFT_ARROW 68
#define RIGHT_ARROW 67
#define UP_ARROW 65
#define DOWN_ARROW 66
#define ESC_KEY 27
#define ENTER_KEY 10

// Colors
#define BLUE "\033[34m"
#define RESET "\033[0m"

struct Employee
{
    unsigned int code;
    char name[40];
    unsigned int netSalary;
};

class Stack
{
private:
    Employee *employees;
    int top;
    int size;

    static int createdStacks;

public:
    Stack(int size)
    {
        this->size = size;
        employees = new Employee[size];
        top = -1;
        createdStacks++;
    }

    ~Stack()
    {
        delete[] employees;
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
};

void setRawMode()
{
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void restoreNormalMode()
{
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= (ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

char getKey()
{
    unsigned char buf[4] = {0};
    read(STDIN_FILENO, buf, 4);

    if (buf[0] == EXTENDED)
    {
        if (buf[1] == EXTENDED_ARROWS)
        {
            return buf[2];
        }
    }
    return buf[0];
}

bool isValidName(const char *name)
{
    for (int i = 0; name[i] != '\0'; i++)
    {
        if (!isalpha(name[i]) && name[i] != ' ')
        {
            return false;
        }
    }
    return true;
}

unsigned int getEmployeeCode()
{
    unsigned int code;
    restoreNormalMode();
    bool isvalid = false;
    while (!isvalid)
    {
        cout << "Enter employee code (positive integer): ";
        cin >> code;
        if (cin.fail() || code <= 0)
        {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Invalid code. Please try again." << endl;
        }
        else
        {
            isvalid = true;
        }
    }
    setRawMode();
    return code;
}

void getEmployeeName(char *name)
{
    restoreNormalMode();
    cin.ignore();
    while (true)
    {
        cout << "Enter employee name (only alphabets): ";
        cin.getline(name, 40);
        if (isValidName(name))
        {
            break;
        }
        else
        {
            cout << "Invalid name. Please enter a name with alphabets only." << endl;
        }
    }
    setRawMode();
}

unsigned int getEmployeeSalary()
{
    unsigned int salary;
    restoreNormalMode();
    while (true)
    {
        cout << "Enter employee net salary: ";
        cin >> salary;
        if (cin.fail() || salary <= 0)
        {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Invalid salary. Please try again." << endl;
        }
        else
        {
            break;
        }
    }
    setRawMode();
    return salary;
}

void centerText(const string &text)
{
    const int terminalWidth = 80;
    int padding = (terminalWidth - text.length()) / 2;
    for (int i = 0; i < padding; i++)
        cout << " ";
    cout << text << endl;
}

int Stack::createdStacks = 0;

int main()
{
    int stackSize;
    cout << "Enter stack size: ";
    cin >> stackSize;

    Stack employeeStack(stackSize);

    setRawMode();

    int selectedOption = 0;
    char key;
    bool flag = true;

    while (flag)
    {
        system("clear");

        centerText((selectedOption == 0 ? BLUE "> Display" RESET : "  Display"));
        centerText((selectedOption == 1 ? BLUE "> Push" RESET : "  Push"));
        centerText((selectedOption == 2 ? BLUE "> Pop" RESET : "  Pop"));
        centerText("Press ESC to exit.");

        key = getKey();

        if (key == ESC_KEY)
        {
            flag = false;
        }

        else if (key == UP_ARROW)
        {
            selectedOption = (selectedOption - 1 + 3) % 3;
        }
        else if (key == DOWN_ARROW)
        {
            selectedOption = (selectedOption + 1) % 3;
        }
        else if (key == ENTER_KEY)
        {
            system("clear");

            if (selectedOption == 0)
            {
                try
                {
                    employeeStack.printStack();
                }
                catch (const runtime_error &e)
                {
                    cout << e.what() << endl;
                }
                cout << "Press ESC to return." << endl;
                while (getKey() != ESC_KEY)
                    ;
            }
            else if (selectedOption == 1)
            {
                if (employeeStack.isFull())
                {
                    cout << "Stack is full! Cannot add more employees." << endl;
                }
                else
                {
                    Employee newEmp;
                    newEmp.code = getEmployeeCode();
                    getEmployeeName(newEmp.name);
                    newEmp.netSalary = getEmployeeSalary();
                    try
                    {
                        employeeStack.push(newEmp);
                        cout << "Employee added successfully!" << endl;
                    }
                    catch (const runtime_error &e)
                    {
                        cout << e.what() << endl;
                    }
                }
                sleep(1);
            }
            else if (selectedOption == 2)
            {
                if (employeeStack.isEmpty())
                {
                    cout << "Stack is empty! No employee to delete." << endl;
                }
                else
                {
                    try
                    {
                        Employee popedEmployee;
                        popedEmployee = employeeStack.pop();
                        cout << "The employee with these data is deleted" << endl;
                        cout << "Code: " << popedEmployee.code << ", Name: " << popedEmployee.name
                             << ", Net Salary: " << popedEmployee.netSalary << endl;
                    }
                    catch (const runtime_error &e)
                    {
                        cout << e.what() << endl;
                    }
                }
                cout << "Press ESC to return." << endl;
                while (getKey() != ESC_KEY)
                    ;
            }
        }
    }

    restoreNormalMode();
    return 0;
}
