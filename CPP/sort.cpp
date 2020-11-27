#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool increase(int a, int b)
{
    return a < b;
}
bool decrease(int a, int b)
{
    return a > b;
}

template <typename T>
bool decrease_t(const T &a, const T &b)
{
    return a > b;
}

int main()
{
    vector<int> a = {1, 3, 5, 7, 2, 4, 6, 8};
    for (auto i = a.begin(); i != a.end(); i++)
    {
        cout << *i << endl;
    }
    cout << "================" << endl;
    sort(a.begin(), a.end(), increase);
    for (auto i = a.begin(); i != a.end(); i++)
    {
        cout << *i << endl;
    }
    cout << "================" << endl;

    // sort(a.begin(), a.end(), decrease);
    sort(a.begin(), a.end(), decrease);
    for (auto i : a)
    {
        cout << i << endl;
    }
    cout << "================" << endl;

    string str("acbedf");
    cout << "str :" << str << endl;
    sort(a.begin(), a.end(), decrease_t);
    cout << "sort:" << str << endl;
}