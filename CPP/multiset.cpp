#include <iostream>
#include <set>

using namespace std;

// multiset能够保证他内部的数据是有序的

int main()
{
    multiset<int> ms;

    // 下方插入时是 4 3 2 1，输出时变为了1 2 3 4
    for (int i = 4; i > 0; i--)
        ms.insert(i);

    for (auto k : ms)
        cout << k << endl;

}