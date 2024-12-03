#include <iostream>
#include <limits>

using namespace std;

struct Complex
{

private: // encapsulate the data
    int real;
    int imag;

public: // publicate methods
    Complex() : real(0), imag(0) {}

    int getReal()
    {
        return real;
    }

    void setReal(int value)
    {
        real = value;
    }

    int getImag()
    {
        return imag;
    }

    void setImag(int value)
    {
        imag = value;
    }

    Complex add(Complex c2)
    {
        Complex result;
        result.real = real + c2.real;
        result.imag = imag + c2.imag;
        return result;
    }

    Complex subtract(Complex c2)
    {
        Complex result;
        result.real = real - c2.real;
        result.imag = imag - c2.imag;
        return result;
    }

    void display()
    {
        if (real == 0 && imag == 0)
        {
            cout << "No data" << endl;
        }
        else if (real == 0)
        {
            cout << imag << "j" << endl;
        }
        else if (imag > 0)
        {
            cout << real << " + " << imag << "j" << endl;
        }
        else
        {
            cout << real << imag << "j" << endl;
        }
    }
};

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
    Complex complex1, complex2, complex3;

    // getting first complex data
    complex1.setReal(validateInteger("Enter real part for the first complex number: "));
    complex1.setImag(validateInteger("Enter imaginary part for the first complex number: "));

    // getting second complex data
    complex2.setReal(validateInteger("Enter real part for the second complex number: "));
    complex2.setImag(validateInteger("Enter imaginary part for the second complex number: "));

    complex3 = complex1.add(complex2);
    cout << "Sum of the two complex numbers is: ";
    complex3.display();

    complex3 = complex1.subtract(complex2);
    cout << "Sub of the two complex numbers is: ";
    complex3.display();

    return 0;
}
