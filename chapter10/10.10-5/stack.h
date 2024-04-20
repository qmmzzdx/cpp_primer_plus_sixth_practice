#ifndef STACK_H_
#define STACK_H_

typedef struct customer
{
    char fullname[35];
    double payment;
} Item;

class Stack
{
private:
    enum {MAX = 10};
    Item items[MAX];
    int top;

public:
    Stack();
    bool isempty() const;
    bool isfull() const;
    bool push(const Item &item);
    bool pop(Item &item);
};

#endif
