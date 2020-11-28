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

bool inorder(char &a, char &b)
{
    return a > b;
    // return 1;
}

template <typename T>
bool increase_t(const T &a, const T &b)
{
    return a < b;
}

int main()
{
    vector<int> a = {1, 3, 5, 7, 2, 4, 6, 8};
    // 使用迭代器进行访问
    cout << "\n========origin========" << endl;
    for (auto i = a.begin(); i != a.end(); i++)
    {
        cout << *i << ",";
    }
    cout << "\n========increase========" << endl;
    sort(a.begin(), a.end(), increase);
    for (auto i = a.begin(); i != a.end(); i++)
    {
        cout << *i << ",";
    }
    cout << "\n========decrease========" << endl;
    // 对他进行降序sort，并输出
    sort(a.begin(), a.end(), decrease);
    for (auto i : a)
    {
        cout << i << ",";
    }
    cout << "\n=======template increase=========" << endl;
    // 似乎不能使用模版来进行vector sort
    sort(a.begin(), a.end(), increase_t<int>);
    for (auto i : a)
    {
        cout << i << ",";
    }
    cout << "\n====================" << endl;
    string str("acbedf");
    cout << "str :" << str << endl;
    // 默认升序
    sort(str.begin(), str.end());
    cout << "sort:" << str << endl;
    // 降序排序
    sort(str.begin(), str.end(), inorder);
    cout << "sort:" << str << endl;
    cout << "=======template increase=========" << endl;
    sort(str.begin(),str.end(),increase_t<char>);
    cout<<"sort:"<<str<<endl;

}