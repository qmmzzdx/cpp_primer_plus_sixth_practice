#ifndef TV_H_
#define TV_H_
#include <iostream>

class Remote; //先声明Remote类然后再定义, 以便编译器有足够的信息编译使用Remote类的方法;

class Tv
{
public:
    friend class Remote;
    enum { Off, On };
    enum { MinVal, MaxVal = 20 };
    enum { Antenna, Cable };
    enum { TV, DVD };
    Tv(int s = Off, int mc = 125) : state(s), volume(5),
                                    maxchannel(mc), channel(2), mode(Cable), input(TV) {}
    void onoff() { state = (state == On) ? Off : On; }
    bool ison() const { return state == On; }
    bool volup();
    bool voldown();
    void chanup();
    void chandown();
    void set_mode() { mode = (mode == Antenna) ? Cable : Antenna; }
    void set_input() { input = (input == TV) ? DVD : TV; }
    void settings() const;
    void set_status(Remote &r); //对Remote类中状态成员进行切换的方法;

private:
    int state;
    int volume;
    int maxchannel;
    int channel;
    int mode;
    int input;
};

class Remote
{
private:
    int mode;
    int status; //状态变量成员;

public:
    friend class Tv;
    enum { Convention, Interaction }; //Convention表示常规模式, Interaction表示互动模式;
    Remote(int m = Tv::TV, int s = Convention) : mode(m), status(s) {} //默认为常规模式;
    bool volup(Tv &t) { return t.volup(); }
    bool voldown(Tv &t) { return t.voldown(); }
    void onoff(Tv &t) { t.onoff(); }
    void chanup(Tv &t) { t.chanup(); }
    void chandown(Tv &t) { t.chandown(); }
    void set_chan(Tv &t, int c) { t.channel = c; }
    void set_mode(Tv &t) { t.set_mode(); }
    void set_input(Tv &t) { t.set_input(); }
    void show_status() const;
};

inline void Tv::set_status(Remote &r)
{
    if (ison())
    {
        r.status = Remote::Convention == r.status ? Remote::Interaction : Remote::Convention;
    }
}

inline void Remote::show_status() const
{
    std::cout << "Status = " << (status == Convention ? "Convention" : "Interaction") << std::endl;
}

#endif
