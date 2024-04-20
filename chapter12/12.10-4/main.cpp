#include <iostream>
#include "stack.h"

int main()
{
    using namespace std;
    Stack st;
    Item temp = 1000UL;
    st.push(temp);
    temp = 2000UL;
    st.push(temp);
    temp = 3000UL;
    st.push(temp);
    Stack st1(st);
    Stack st2;
    st2 = st1;
    cout << "Here are some stack contents:" << endl;
    cout << "Stack st:" << endl;
    cout << st;
    cout << "Stack st1:" << endl;
    cout << st1;
    cout << "Stack st2:" << endl;
    cout << st2;
    cout << "Bye\n";

    return 0;
}
