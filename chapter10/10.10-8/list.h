#ifndef LIST_H_
#define LIST_H_

typedef int Item;

class List
{
private:
    static const int MAX = 10;
    Item items[MAX];
    int index;

public:
    List();
    void add_data(Item item);
    bool is_empty();
    bool is_full();
    void visit(void (*pf)(Item &));
};

#endif
