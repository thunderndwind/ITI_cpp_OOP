#include <iostream>
#include "customString.h"

using namespace std;

int main()
{
    customString str1;
    customString str2(20);
    customString str3("Hello");
    customString str4 = str3;

    cout << "Length of str1: " << str1.getLength() << endl;
    cout << "Length of str2: " << str2.getLength() << endl;
    cout << "Length of str3: " << str3.getLength() << endl;
    cout << "Length of str4: " << str4.getLength() << endl;

    customString str5 = str3 + " World";
    cout << "str5: " << str5.getLength() << endl;

    if (str3 == str4)
    {
        cout << "str3 and str4 are equal" << endl;
    }
    else
    {
        cout << "str3 and str4 are not equal" << endl;
    }

    str1 = str3;
    cout << "str1: " << str1.getLength() << endl;

    return 0;
}
