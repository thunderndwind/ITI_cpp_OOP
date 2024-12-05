#include <iostream>
#include "customList.h"

int main()
{
    customList list1;
    list1.push(10);
    list1.push(20);
    list1.push(30);

    customList list2;
    list2.push(40);
    list2.push(50);

    std::cout << "List 1 Length: " << list1.getLength() << std::endl;
    std::cout << "List 2 Length: " << list2.getLength() << std::endl;

    customList list3 = list1 + list2;
    std::cout << "List 3 Length (after concatenation): " << list3.getLength() << std::endl;

    std::cout << "List 3 content:" << std::endl;
    for (unsigned int i = 0; i < list3.getLength(); ++i)
    {
        std::cout << list3.get(i) << std::endl;
    }

    if (list1 == list2)
    {
        std::cout << "List 1 and List 2 are equal" << std::endl;
    }
    else
    {
        std::cout << "List 1 and List 2 are not equal" << std::endl;
    }

    list1.pop();
    std::cout << "List 1 Length after pop: " << list1.getLength() << std::endl;

    return 0;
}
