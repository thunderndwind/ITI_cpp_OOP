#include <iostream>
#include <limits>

using namespace std;

class Complex
{

private: // encapsulate the data
    int real;
    int img;

public: // publicate methods
    // Constructors
    Complex()
    {
        real = 0;
        img = 0;
    }
    Complex(int initValue)
    {
        real = initValue;
        img = initValue;
    }
    Complex(int real, int img)
    {
        this->real = real;
        this->img = img;
    }

    // Copy constructor
    Complex(Complex &c)
    {
    }

    // Destructor
    ~Complex()
    {
        // cout << "Complex with real = " << real << " and Imaginary = " << img << " is deleted." << endl;
    }

    // Methods
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

    Complex add(Complex c2)
    {
        Complex result(0, 0);
        result.real = this->real + c2.real;
        result.img = this->img + c2.img;
        return result;
    }

    Complex operator+(Complex c2)
    {
        Complex result(0, 0);
        result.real = this->real + c2.real;
        result.img = this->img + c2.img;
        return result;
    }

    Complex operator+(int number)
    {
        Complex result;
        result.real = this->real + number;
        result.img = this->img + number;
        return result;
    }

    void operator+=(int number)
    {
        this->real = this->real + number;
        this->img = this->img + number;
    }

    void operator+=(Complex c)
    {
        this->real = this->real + c.real;
        this->img = this->img + c.img;
    }

    Complex operator++()
    {
        this->real++;
        this->img++;
        return *this;
    }

    Complex operator++(int value)
    {
        Complex result;
        result.real = this->real;
        result.img = this->img;
        (*this)++;
        return result;
    }

    Complex operator--()
    {
        this->real--;
        this->img--;
        return *this;
    }

    Complex operator--(int value)
    {
        Complex result;
        result.real = this->real;
        result.img = this->img;
        (*this)--;
        return result;
    }

    Complex subtract(Complex c2)
    {
        Complex result(0, 0);
        result.real = this->real - c2.real;
        result.img = this->img - c2.img;
        return result;
    }

    Complex operator-(Complex c2)
    {
        Complex result;
        result.real = this->real - c2.real;
        result.img = this->img - c2.img;
        return result;
    }

    Complex operator-(int number)
    {
        Complex result;
        result.real = this->real - number;
        result.img = this->img - number;
        return result;
    }

    void operator-=(int number)
    {
        this->real = this->real - number;
        this->img = this->img - number;
    }

    void operator-=(Complex c)
    {
        this->real = this->real - c.real;
        this->img = this->img - c.img;
    }

    void operator=(Complex s)
    {
        this->real = s.real;
        this->img = s.img;
    }

    bool operator==(Complex s)
    {
        return (this->real == s.real && this->img == s.img);
    }

    operator float()
    {
        return real;
    }

    void display()
    {
        if (real == 0 && img == 0)
        {
            cout << "0" << endl;
        }
        else if (real == 0)
        {
            cout << this->img << "j" << endl;
        }
        else if (img == 0)
        {
            cout << real << endl;
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

Complex operator+(int number, Complex c)
{
    Complex result;
    result.setReal(c.getReal() + number);
    result.setImaginary(c.getImaginary() + number);
    return result;
}

Complex operator-(int number, Complex c)
{
    Complex result;
    result.setReal(c.getReal() - number);
    result.setImaginary(c.getImaginary() - number);
    return result;
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
    Complex complex1(1, 1), complex2(1, 1);
    complex1.display();
    complex2.display();

    // complex1.setComplex(1, 1);
    // complex2.setComplex(3, 3);

    // // getting first complex data
    // complex1.setReal(validateInteger("Enter real part for the first complex number: "));
    // complex1.setImaginary(validateInteger("Enter imaginary part for the first complex number: "));

    // // getting second complex data
    // complex2.setReal(validateInteger("Enter real part for the second complex number: "));
    // complex2.setImaginary(validateInteger("Enter imaginary part for the second complex number: "));

    Complex *complex3 = new Complex(0, 0);
    *complex3 = complex1 + complex2;

    cout << "Sum of the two complex numbers is: ";
    (*complex3).display();

    *complex3 = complex1.subtract(complex2);
    cout << "Sub of the two complex numbers is: ";
    (*complex3).display();

    delete complex3;

    return 0;
}
