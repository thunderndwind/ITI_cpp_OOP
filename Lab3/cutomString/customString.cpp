#include "customString.h"

customString::customString()
{
    length = 16;
    str = new char[length + 1];
    str[0] = '\0';
}

customString::customString(unsigned int len)
{
    length = len;
    str = new char[length + 1];
    str[0] = '\0';
}

customString::customString(const char *s)
{
    length = customStrlen(s);
    str = new char[length + 1];
    customStrcpy(str, s);
}

customString::customString(const customString &s)
{
    length = s.length;
    str = new char[length + 1];
    customStrcpy(str, s.str);
}

customString::~customString()
{
    delete[] str;
}

unsigned int customString::getLength() const
{
    return length;
}

customString &customString::operator=(const customString &s)
{
    if (this != &s)
    {
        delete[] str;
        length = s.length;
        str = new char[length + 1];
        customStrcpy(str, s.str);
    }
    return *this;
}

customString customString::operator+(const customString &s) const
{
    customString result(length + s.length);
    customStrcpy(result.str, str);
    customStrcat(result.str, s.str);
    return result;
}

bool customString::operator==(const customString &s) const
{
    if (length != s.length)
    {
        return false;
    }
    for (unsigned int i = 0; i < length; ++i)
    {
        if (str[i] != s.str[i])
        {
            return false;
        }
    }
    return true;
}

unsigned int customString::customStrlen(const char *s) const
{
    unsigned int len = 0;
    while (s[len] != '\0')
    {
        ++len;
    }
    return len;
}

void customString::customStrcpy(char *dest, const char *src) const
{
    unsigned int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        ++i;
    }
    dest[i] = '\0';
}

void customString::customStrcat(char *dest, const char *src) const
{
    unsigned int i = 0;
    while (dest[i] != '\0')
    {
        ++i;
    }
    unsigned int j = 0;
    while (src[j] != '\0')
    {
        dest[i] = src[j];
        ++i;
        ++j;
    }
    dest[i] = '\0';
}
