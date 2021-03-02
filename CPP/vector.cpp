#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int m = 3, n = 2;
    // 还可以这样去创建一个固定大小的二维vector
    vector<vector<int>> t(n, vector<int>(m));
    t[1][1] = 999;
    cout << t[1][1] << endl;
    cout << t.size() << endl;
    cout << t[0].size() << endl;
    cout << "----------------------" << endl;
    // 其实这个用法是这样的，第一个是个数，第二个是初始值
    // 这里的初始值就是int类型，上边的初始值就是vector<int>类型
    vector<int> t1(n, m);
    for (auto k : t1)
        cout << k << endl;
    cout << "----------------------" << endl;
    // 或者可以这样resize,一个是带初值的resize，一个不带初值（默认为0），
    vector<vector<int>> sums;
    sums.resize(10, vector<int>(10 + 1));
    // sums.resize(10,vector<int>(10+1,111));
    cout << sums[1][2] << endl;
    cout << sums.size() << endl;
    cout << sums[0].size() << endl;
}