#include <cctype>
#include <cstring>
#include "string2.h"
using std::cin;
using std::cout;

int String::num_strings = 0;

int String::HowMany()
{
    return num_strings;
}

String::String(const char *s)
{
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    num_strings++;
}

String::String()
{
    len = 4;
    str = new char[1];
    str[0] = '\0';
    num_strings++;
}

String::String(const String &st)
{
    num_strings++;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
}

String::~String()
{
    --num_strings;
    delete[] str;
}

String &String::operator=(const String &st)
{
    if (this == &st)
    {
        return *this;
    }
    delete[] str;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    return *this;
}

String &String::operator=(const char *s)
{
    delete[] str;
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    return *this;
}

String String::operator+(const char *s)
{
    int length = strlen(s) + len;
    char *temp = new char[length + 1];
    strcpy(temp, str);
    strcat(temp, s);
    String new_str(temp);
    delete[] temp;
    return new_str;
}

char &String::operator[](int i)
{
    return str[i];
}

const char &String::operator[](int i) const
{
    return str[i];
}

bool operator<(const String &st1, const String &st2)
{
    return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String &st1, const String &st2)
{
    return st2 < st1;
}

bool operator==(const String &st1, const String &st2)
{
    return (std::strcmp(st1.str, st2.str) == 0);
}

ostream &operator<<(ostream &os, const String &st)
{
    os << st.str;
    return os;
}

istream &operator>>(istream &is, String &st)
{
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if (is)
    {
        st = temp;
    }
    while (is && is.get() != '\n')
        continue;
    return is;
}

String operator+(const char *s, const String &st)
{
    int length = strlen(s) + st.len;
    char *temp = new char[length + 1];
    strcpy(temp, s);
    strcat(temp, st.str);
    String new_str(temp);
    delete[] temp;
    return new_str;
}

String operator+(const String &st1, const String &st2)
{
    int length = st1.len + st2.len;
    char *temp = new char[length + 1];
    strcpy(temp, st1.str);
    strcat(temp, st2.str);
    String new_str(temp);
    delete[] temp;
    return new_str;
}

void String::stringlow()
{
    for (int i = 0; i < len; i++)
    {
        str[i] = tolower(str[i]);
    }
}

void String::stringup()
{
    for (int i = 0; i < len; i++)
    {
        str[i] = toupper(str[i]);
    }
}

unsigned String::has(const char s) const
{
    unsigned count = 0;

    for (int i = 0; i < len; i++)
    {
        count += (s == str[i]);
    }
    return count;
}
