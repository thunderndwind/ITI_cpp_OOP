#include <iostream>
#include "customList.h"

using namespace std;

int main()
{
    customList<int> list1;
    list1.push(10);
    list1.push(20);
    list1.push(30);

    customList<float> list2;
    list1.push(10.1);
    list1.push(20.2);
    list1.push(30.3);

    customList<int> list3;
    list1.push(40);
    list1.push(50);

    customList<float> list4;
    list2.push(40.4);
    list2.push(50.5);

    cout << "List 1 Length: " << list1.getLength() << endl;
    cout << "List 2 Length: " << list2.getLength() << endl;

    customList list5 = list1 + list3;
    cout << "List 3 Length (after concatenation): " << list5.getLength() << endl;

    customList list6 = list2 + list4;
    cout << "List 3 Length (after concatenation): " << list6.getLength() << endl;

    cout << "List 3 content:" << endl;
    for (unsigned int i = 0; i < list3.getLength(); ++i)
    {
        cout << list3.get(i) << endl;
    }

    if (list1 == list3)
    {
        cout << "List 1 and List 2 are equal" << endl;
    }
    else
    {
        cout << "List 1 and List 2 are not equal" << endl;
    }

    list1.pop();
    cout << "List 1 Length after pop: " << list1.getLength() << endl;

    return 0;
}
