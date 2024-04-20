#ifndef STONEWT_H_
#define STONEWT_H_
#include <iostream>

class Stonewt
{
private:
    enum{ Lbs_per_stn = 14 };
    int stone;
    double pds_left;
    double pounds;

public:
    explicit Stonewt(double lbs);
    Stonewt(int stn, double lbs);
    Stonewt();
    ~Stonewt();
    bool operator<(const Stonewt &st) const;
    bool operator>(const Stonewt &st) const;
    bool operator<=(const Stonewt &st) const;
    bool operator>=(const Stonewt &st) const;
    bool operator==(const Stonewt &st) const;
    bool operator!=(const Stonewt &st) const;
    friend std::ostream &operator<<(std::ostream &os, const Stonewt &st);
};

#endif
