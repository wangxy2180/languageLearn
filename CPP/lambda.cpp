#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    auto f = [] { return 42; };
    cout << "lambda:" << f() << endl;

    vector<int> a = {1, 3, 5, 7, 2, 4, 6, 8};
    for (auto i = a.begin(); i != a.end(); i++)
    {
        cout << *i << endl;
    }
    cout << "================" << endl;
    sort(a.begin(), a.end(), [](int a, int b) { return a > b; });

    for (auto i = a.begin(); i != a.end(); i++)
    {
        cout << *i << endl;
    }

    for(auto i : a)
    {
        cout<<"i:"<<i<<endl;
    }

}