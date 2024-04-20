#include <iostream>
#include <cstdlib>
#include <ctime>
#include "queue.h"
using namespace std;
const int MIN_PER_HR = 60;

bool newcustomer(double x);

int main()
{
    srand(time(0));

    cout << "Case Study: Bank of Heather Automatic Teller\n";
    cout << "Enter maximum size of queue: ";
    int qs;
    cin >> qs;
    Queue line1(qs); //构造第一台ATM机;
    Queue line2(qs); //构造第二台ATM机;

    cout << "Enter the number of simulation hours: ";
    int hours;
    cin >> hours;
    long cyclelimit = MIN_PER_HR * hours;

    cout << "Enter the average number of customers per hour: ";
    double perhour;
    cin >> perhour;
    double min_per_cust;
    min_per_cust = MIN_PER_HR / perhour;

    long turnaways = 0;
    long customers = 0;
    long served = 0;
    long sum_line = 0;
    int wait_time1 = 0; //第一台ATM机的等待时间;
    int wait_time2 = 0; //第二台ATM机的等待时间;
    long line_wait = 0;

    for (int cycle = 0; cycle < cyclelimit; cycle++)
    {
        Item temp;
        if (newcustomer(min_per_cust))
        {
            if (line1.isfull() && line2.isfull())
            {
                turnaways++;
            }
            else
            {
                customers++;
                temp.set(cycle);
                if (line1.queuecount() < line2.queuecount())
                {
                    line1.enqueue(temp);
                }
                else
                {
                    line2.enqueue(temp);
                }
            }
        }
        if (wait_time1 <= 0 && !line1.isempty())
        {
            line1.dequeue(temp);
            wait_time1 = temp.ptime();
            line_wait += cycle - temp.when();
            served++;
        }
        if (wait_time1 > 0)
        {
            wait_time1--;
        }
        sum_line += line1.queuecount();
        if (wait_time2 <= 0 && !line2.isempty())
        {
            line2.dequeue(temp);
            wait_time2 = temp.ptime();
            line_wait += cycle - temp.when();
            served++;
        }
        if (wait_time2 > 0)
        {
            wait_time2--;
        }
        sum_line += line2.queuecount();
    }

    if (customers > 0)
    {
        cout << "customers accepted: " << customers << endl;
        cout << "  customers served: " << served << endl;
        cout << "         turnaways: " << turnaways << endl;
        cout << "average queue size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << (double)sum_line / cyclelimit << endl;
        cout << " average wait time: ";
        cout << (double)line_wait / served << " minutes\n";
    }
    else
    {
        cout << "No customers!\n";
    }
    cout << "Done!\n";

    return 0;
}

bool newcustomer(double x)
{
    return (std::rand() * x / RAND_MAX < 1);
}
