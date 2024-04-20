#ifndef WORKER_H_
#define WORKER_H_
#include <string>

class Worker
{
private:
    std::string fullname;
    long id;

public:
    Worker() : fullname("no one"), id(0L) {}
    Worker(const std::string &s, long n) : fullname(s), id(n) {}
    ~Worker();
    void Set();
    void Show() const;
};

#endif
