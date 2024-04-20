#ifndef PLORG_H_
#define PLORG_H_

class Plorg
{
private:
    char fullname[20];
    int ci;

public:
    Plorg();
    void reset_ci();
    void show_plorg() const;
    void create_new_plorg(const char *newname);
};

#endif
