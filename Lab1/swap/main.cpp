#include <iostream>
#include <limits>
#include <array>
#include <tuple>

using namespace std;

array<int, 2> swapByValueArray(int number1, int number2)
{
    array<int, 2> swapped = {number2, number1};
    return swapped;
}

tuple<int, int> swapByValueTuple(int number1, int number2)
{
    return make_tuple(number2, number1);
}

void swapByAddress(int *number1, int *number2)
{
    *number1 = *number1 ^ *number2;
    *number2 = *number1 ^ *number2;
    *number1 = *number1 ^ *number2;
}

void swapByReference(int &number1, int &number2)
{
    number1 = number1 ^ number2;
    number2 = number1 ^ number2;
    number1 = number1 ^ number2;
}

int validateInteger(const string message)
{
    int value;
    while (true)
    {
        cout << message;
        cin >> value;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter an integer.\n";
        }
        else
        {
            return value;
        }
    }
}

int main()
{
    int number1 = validateInteger("Enter the first number to be swapped: ");
    int number2 = validateInteger("Enter the second number to be swapped: ");

    cout << "Original values:\nnumber1 = " << number1 << ", number2 = " << number2 << endl;

    array<int, 2> swappedArray = swapByValueArray(number1, number2);
    number1 = swappedArray[0];
    number2 = swappedArray[1];
    cout << "Swapped using array: number1 = " << number1 << ", number2 = " << number2 << endl;

    tie(number1, number2) = swapByValueTuple(number1, number2);
    cout << "Swapped using tuple: number1 = " << number1 << ", number2 = " << number2 << endl;

    swapByAddress(&number1, &number2);
    cout << "Swapped using address: number1 = " << number1 << ", number2 = " << number2 << endl;

    swapByReference(number1, number2);
    cout << "Swapped using reference: number1 = " << number1 << ", number2 = " << number2 << endl;

    return 0;
}
