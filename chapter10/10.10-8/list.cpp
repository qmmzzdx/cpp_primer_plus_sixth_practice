#include <iostream>
#include "list.h"

List::List()
{
    index = 0;
}

void List::add_data(Item item)
{
    items[index++] = item;
}

bool List::is_empty()
{
    return 0 == index;
}

bool List::is_full()
{
    return MAX == index;
}

void List::visit(void (*pf)(Item &))
{
    for (int i = 0; i < this->index; i++)
    {
        (*pf)(this->items[i]);
    }
}
