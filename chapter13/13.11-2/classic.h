#ifndef CLASSIC_H_
#define CLASSIC_H_
#include "cd.h"

class Classic : public Cd
{
private:
    char *cdstr;

public:
    Classic();
    Classic(const char *s1, const char *s2, const char *s3, int n, double x);
    Classic(const char *s, const Cd &d);
    ~Classic();
    virtual void Report() const;
    Classic &operator=(const Classic &cs);
};

#endif
