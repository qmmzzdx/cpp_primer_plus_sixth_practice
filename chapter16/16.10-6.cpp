#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue>
using namespace std;
const int MIN_PER_HR = 60;

class Customer //类声明及定义放置在此;
{
private:
    long arrive;
    int processtime;

public:
    Customer() { arrive = processtime = 0; }
    void set(long when) { processtime = rand() % 3 + 1, arrive = when; }
    long when() const { return arrive; }
    int ptime() const { return processtime; }
};
using Item = Customer; //Item类型为Customer;

bool newcustomer(double x);

int main()
{
    srand(time(0));

    cout << "Case Study: Bank of Heather Automatic Teller\n";
    cout << "Enter maximum size of queue: ";
    int qs;
    cin >> qs;        //队列容量的最大值;
    queue<Item> line; //声明一个queue模板类型为Item;

    cout << "Enter the number of simulation hours: ";
    int hours;
    cin >> hours;
    long cyclelimit = MIN_PER_HR * hours;

    cout << "Enter the average number of customers per hour: ";
    double perhour;
    cin >> perhour;
    double min_per_cust;
    min_per_cust = MIN_PER_HR / perhour;

    Item temp;
    long turnaways = 0L;
    long customers = 0L;
    long served = 0L;
    long sum_line = 0L;
    int wait_time = 0;
    long line_wait = 0L;

    for (int cycle = 0; cycle < cyclelimit; cycle++)
    {
        if (newcustomer(min_per_cust))
        {
            if (line.size() == qs) //容量达到最大值;
            {
                turnaways++;
            }
            else
            {
                customers++;
                temp.set(cycle);
                line.push(temp); //入队;
            }
        }
        if (wait_time <= 0 && !line.empty())
        {
            temp = line.front(); //获取队头元素;
            line.pop();          //队头元素出队;
            wait_time = temp.ptime();
            line_wait += cycle - temp.when();
            served++;
        }
        if (wait_time > 0)
        {
            wait_time--;
        }
        sum_line += line.size(); //改为获取队列当前长度;
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
    return (rand() * x / RAND_MAX < 1);
}
