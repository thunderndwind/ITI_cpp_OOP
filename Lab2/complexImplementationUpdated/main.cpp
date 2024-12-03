#include <iostream>
#include <limits>

using namespace std;

class Complex
{

private: // encapsulate the data
    int real;
    int img;
    bool isHeapAllocated;

public: // publicate methods
    // constructors
    Complex()
    {
        real = 0;
        img = 0;
        isHeapAllocated = false;
    }
    Complex(int initValue)
    {
        real = initValue;
        img = initValue;
        isHeapAllocated = false;
    }
    Complex(int real, int img)
    {
        this->real = real;
        this->img = img;
        isHeapAllocated = false;
    }

    // Destructor
    ~Complex()
    {
        if (isHeapAllocated)
        {
            cout << "Complex with real = " << real << " and Imaginary = " << img << " is deleted." << endl;
        }
    }

    // methods
    void setComplex(int real, int img)
    {
        this->real = real;
        this->img = img;
    }

    int getReal()
    {
        return real;
    }

    void setReal(int real)
    {
        this->real = real;
    }

    int getImaginary()
    {
        return img;
    }

    void setImaginary(int img)
    {
        this->img = img;
    }

    void setHeapAllocated()
    {
        isHeapAllocated = true;
    }

    Complex add(Complex c2)
    {
        Complex result;
        result.real = real + c2.real;
        result.img = img + c2.img;
        return result;
    }

    Complex subtract(Complex c2)
    {
        Complex result;
        result.real = real - c2.real;
        result.img = img - c2.img;
        return result;
    }

    void display()
    {
        if (real == 0 && img == 0)
        {
            cout << "No data" << endl;
        }
        else if (real == 0)
        {
            cout << img << "j" << endl;
        }
        else if (img > 0)
        {
            cout << real << "+" << img << "j" << endl;
        }
        else
        {
            cout << real << img << "j" << endl;
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
    Complex complex1, complex2;

    // getting first complex data
    complex1.setReal(validateInteger("Enter real part for the first complex number: "));
    complex1.setImaginary(validateInteger("Enter imaginary part for the first complex number: "));

    // getting second complex data
    complex2.setReal(validateInteger("Enter real part for the second complex number: "));
    complex2.setImaginary(validateInteger("Enter imaginary part for the second complex number: "));

    Complex *complex3 = new Complex();

    *complex3 = complex1.add(complex2);
    cout << "Sum of the two complex numbers is: ";
    (*complex3).display();

    *complex3 = complex1.subtract(complex2);
    cout << "Sub of the two complex numbers is: ";
    (*complex3).display();

    complex3->setHeapAllocated();
    delete complex3;

    return 0;
}
