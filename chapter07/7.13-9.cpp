#include <iostream>
using namespace std;

const int SLEN = 30;

struct student
{
    char fullname[SLEN];
    char hobby[SLEN];
    int ooplevel;
};

int getinfo(student pa[], int n);
void display1(student st);
void display2(const student *ps);
void display3(const student pa[], int n);

int main()
{
    cout << "Enter class size: ";
    int class_size;
    cin >> class_size;
    while (cin.get() != '\n')
    {
        continue;
    }

    student *ptr_stu = new student[class_size];
    int entered = getinfo(ptr_stu, class_size);
    for (int i = 0; i < entered; i++)
    {
        display1(ptr_stu[i]);
        display2(&ptr_stu[i]);
    }
    display3(ptr_stu, entered);
    delete[] ptr_stu;
    cout << "Done\n";

    return 0;
}

int getinfo(student pa[], int n)
{
    int i;

    cout << "You can enter up to " << n;
    cout << " students' messages (enter to terminate)." << endl;
    for (i = 0; i < n; i++)
    {
        cout << "Student #" << i + 1 << ": " << endl;
        cout << "Enter the fullname(a blank line to quit): ";
        cin.getline(pa[i].fullname, SLEN);
        if ('\0' == pa[i].fullname[0])
        {
            break;
        }
        cout << "Enter the hobby: ";
        cin.getline(pa[i].hobby, SLEN);
        cout << "Enter the ooplevel: ";
        while (!(cin >> pa[i].ooplevel))
        {
            cin.clear();
            while (cin.get() != '\n')
            {
                continue;
            }
            cout << "Please enter an number: ";
        }
        cin.get();
    }
    return i;
}

void display1(student st)
{
    cout << "\nName: " << st.fullname << endl;
    cout << "Hobby: " << st.hobby << endl;
    cout << "Ooplevel: " << st.ooplevel << endl;
}

void display2(const student *ps)
{
    cout << "\nName: " << ps->fullname << endl;
    cout << "Hobby: " << ps->hobby << endl;
    cout << "Ooplevel: " << ps->ooplevel << endl;
}

void display3(const student pa[], int n)
{
    if (n > 0)
    {
        cout << "\nAll students' information:" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << "Name: " << pa[i].fullname << endl;
            cout << "Hobby: " << pa[i].hobby << endl;
            cout << "Ooplevel: " << pa[i].ooplevel << endl;
        }
    }
}
