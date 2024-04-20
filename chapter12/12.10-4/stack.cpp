#include "stack.h"

Stack::Stack(int n)
{
    top = 0;
    if (n > MAX)
    {
        std::cout << "The length of stack can't exceed 10.\n";
        std::cout << "So initialize the length to 10.\n";
        size = MAX;
    }
    else if (n < 0)
    {
        std::cout << "The length of stack can't less than 0.\n";
        std::cout << "So initialize the length to 10.\n";
        size = MAX;
    }
    else
    {
        size = n;
    }
    pitems = new Item[size];
}

Stack::Stack(const Stack &st)
{
    size = st.size, top = st.top;
    pitems = new Item[size];
    for (int i = 0; i < top; i++)
    {
        pitems[i] = st.pitems[i];
    }
}

Stack::~Stack()
{
    delete[] pitems;
}

bool Stack::isempty() const
{
    return top == 0;
}

bool Stack::isfull() const
{
    return top == n;
}

bool Stack::push(const Item &item)
{
    if (top < size)
    {
        pitems[top++] = item;
        return true;
    }
    else
    {
        return false;
    }
}

bool Stack::pop(Item &item)
{
    if (top > 0)
    {
        item = pitems[--top];
        return true;
    }
    else
    {
        return false;
    }
}

Stack &Stack::operator=(const Stack &st)
{
    if (this == &st)
    {
        return *this;
    }
    delete[] pitems;
    size = st.size;
    top = st.top;
    pitems = new Item[size];
    for (int i = 0; i < top; i++)
    {
        pitems[i] = st.pitems[i];
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Stack &st)
{
    for (int i = st.top - 1; i >= 0; i--)
    {
        os << st.pitems[i] << std::endl;
    }
    return os;
}
