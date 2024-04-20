#ifndef PERSONMI_H_
#define PERSONMI_H_
#include <string>
using std::string;

class Person
{
private:
    string firstname;
    string lastname;

protected:
    virtual void Data() const; //虚保护方法打印基类成员信息, 使得派生类可以间接访问;
    virtual void Get();        //虚保护方法获取基类成员信息, 使得派生类可以间接访问;

public:
    Person() : firstname("no"), lastname("one") {}
    Person(const string &fname, const string &lname) : firstname(fname), lastname(lname) {}
    virtual ~Person() = 0;
    virtual void Set() = 0;
    virtual void Show() const = 0;
};

class Gunslinger : virtual public Person
{
private:
    int nicks;

protected:
    void Data() const; //重新定义保护方法;
    void Get();

public:
    Gunslinger() : Person(), nicks(0) {}
    Gunslinger(const string &f, const string &l, int n) : Person(f, l), nicks(n) {}
    Gunslinger(const Person &p, int n) : Person(p), nicks(n) {}
    void Set();
    void Show() const;
    double Draw() const; //打印枪手的拔枪时间;
};

class PokerPlayer : virtual public Person
{
protected:
    void Data() const; //重新定义保护方法;

public:
    PokerPlayer() : Person("no", "one") {}
    PokerPlayer(const string &f, const string &l) : Person(f, l) {}
    PokerPlayer(const Person &p) : Person(p) {}
    void Set();
    void Show() const;
    int Draw() const; //表示扑克牌的值;
};

class BadDude : public Gunslinger, public PokerPlayer
{
protected:
    void Data() const; //重新定义保护方法;
    void Get();

public:
    BadDude() {}
    BadDude(const string &f, const string &l, int n) : Person(f, l), Gunslinger(f, l, n), PokerPlayer(f, l) {}
    BadDude(const Person &p, int n) : Person(p), Gunslinger(p, n), PokerPlayer(p) {}
    BadDude(const Gunslinger &g) : Person(g), Gunslinger(g), PokerPlayer(g) {}
    BadDude(const PokerPlayer &p, int n) : Person(p), Gunslinger(p, n), PokerPlayer(p) {}
    void Set();
    void Show() const;
    double Gdraw() const; //打印坏蛋拔枪的时间;
    int Cdraw() const;    //打印下一张扑克牌的值;
};

#endif
