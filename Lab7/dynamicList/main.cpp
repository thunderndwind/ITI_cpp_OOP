#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>
#include <string>

using namespace std;

class VoidElement
{
public:
    char *type;
    void *value;

    VoidElement(void *value, const char *type)
    {
        this->value = value;
        this->type = new char[strlen(type) + 1];
        strcpy(this->type, type);
    }

    ~VoidElement()
    {
        delete[] type;
    }
};

class DynamicList
{
private:
    std::vector<VoidElement *> list;

public:
    ~DynamicList()
    {
        for (auto elem : list)
        {
            delete elem;
        }
    }

    void addElement(void *value, const char *type)
    {
        list.push_back(new VoidElement(value, type));
    }

    void *getElement(int index)
    {
        if (index >= 0 && index < list.size())
        {
            return list[index]->value;
        }
        throw "Element not found.";
    }

    template <typename T>
    T &getElementByType(int index)
    {
        if (index >= 0 && index < list.size())
        {
            VoidElement *elem = list[index];
            if (strcmp(elem->type, typeid(T).name()) == 0)
            {
                return *static_cast<T *>(elem->value);
            }
        }
        throw "Element not found or type mismatch.";
    }

    void removeElement(int index)
    {
        if (index >= 0 && index < list.size())
        {
            delete list[index];
            list.erase(list.begin() + index);
        }
    }

    size_t size() const
    {
        return list.size();
    }
};

int main()
{
    DynamicList list;

    int *intValue = new int(42);

    double *doubleValue = new double(3.14);

    char *strValue = "Hello!";

    list.addElement(intValue, typeid(int).name());
    list.addElement(doubleValue, typeid(double).name());
    list.addElement((void *)strValue, typeid(char *).name());

    cout << "Element 0 (int): " << *static_cast<int *>(list.getElement(0)) << endl;
    cout << "Element 1 (double): " << *static_cast<double *>(list.getElement(1)) << endl;
    cout << "Element 2 (string): " << static_cast<char *>(list.getElement(2)) << endl;

    cout << "Element 0 (int, by type): " << list.getElementByType<int>(0) << endl;
    cout << "Element 1 (double, by type): " << list.getElementByType<double>(1) << endl;

    list.removeElement(1);
    cout << "Size after removal: " << list.size() << std::endl;

    return 0;
}
