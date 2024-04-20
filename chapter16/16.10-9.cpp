#include <iostream>
#include <ctime>
#include <cstdlib>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;
const long big[3] = {100000, 1000000, 10000000};

void test_sort(long n);

int main()
{
    for (int i = 0; i < 3; i++)
    {
        test_sort(big[i]);
    }
    cout << "Done." << endl;

    return 0;
}

void test_sort(long n)
{
    srand(time(0));
    vector<int> vi0(n); //声明一个含有n个元素的向量数组;

    for (int &x : vi0)
    {
        x = rand() % 100 + 1; //提供初始值;
    }
    vector<int> vi(vi0);
    list<int> li(n);
    copy(vi0.begin(), vi0.end(), li.begin());

    cout << "Test sorting " << n << " elements:" << endl;
    clock_t start = clock();
    sort(vi.begin(), vi.end());
    clock_t end = clock();
    cout << "Sort vi: " << static_cast<double>(end - start) / CLOCKS_PER_SEC << "s." << endl;
    //计算使用STL的sort对vi排序的时间;

    start = clock();
    li.sort();
    end = clock();
    cout << "Sort li: " << static_cast<double>(end - start) / CLOCKS_PER_SEC << "s." << endl;
    //计算使用list的sort方法对li排序的时间;

    sort(vi0.begin(), vi0.end());
    copy(vi0.begin(), vi0.end(), li.begin());
    start = clock();
    copy(li.begin(), li.end(), vi.begin());
    sort(vi.begin(), vi.end());
    copy(vi.begin(), vi.end(), li.begin());
    end = clock();
    cout << "Sort vi and copy to li: " << static_cast<double>(end - start) / CLOCKS_PER_SEC << "s." << endl;
    //计算将li的内容复制到vi中并对vi进行排序后再将结果复制回li中的时间;
}
