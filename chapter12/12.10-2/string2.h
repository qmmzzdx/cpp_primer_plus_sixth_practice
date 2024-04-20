#ifndef STRING2_H_
#define STRING2_H_
#include <iostream>
using std::istream;
using std::ostream;

class String
{
private:
    char *str;                    //字符串首字符指针;
    int len;                      //记录字符串长度;
    static int num_strings;       //记录构造的字符串数目;
    static const int CINLIM = 80; //限制输入字符个数;

public:
    String(const char *s);
    String();
    String(const String &st);
    ~String();
    int length() const { return len; }
    String &operator=(const String &st);
    String &operator=(const char *s);
    String operator+(const char *s);
    char &operator[](int i);
    const char &operator[](int i) const;
    friend bool operator<(const String &st1, const String &st2);
    friend bool operator>(const String &st1, const String &st2);
    friend bool operator==(const String &st1, const String &st2);
    friend ostream &operator<<(ostream &os, const String &st);
    friend istream &operator>>(istream &is, String &st);
    friend String operator+(const char *s, const String &st);
    friend String operator+(const String &st1, const String &st2);
    void stringlow();
    void stringup();
    unsigned has(const char s) const;
    static int HowMany();
};

#endif
