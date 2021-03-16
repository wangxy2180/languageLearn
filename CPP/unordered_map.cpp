#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;
// unordered_map使用方括号[]构建

template <class T, class P>
void mp_display(const unordered_map<T, P> &in)
{
    for (auto k : in)
    {
        cout << "[" << k.first << ":" << k.second << "]" << endl;
    }
}

int main()
{
    // 0.初始化
    unordered_map<string, int> init;
    init = {{"jack", 19}, {"aba", 22}};

    unordered_map<string, int> age;
    // 一些经典用法
    // 1.插入 增
    age.insert({{"jack", 18}, {"tom", 20}, {"Peter", 33}});
    age["steven"] = 222;
    mp_display(age);
    cout << "-----------------------------------" << endl;
    // 2.删除
    age.erase("jack");
    mp_display(age);
    cout << "-----------------------------------" << endl;
    // 3.修改
    age.at("Peter") = 44;
    age["tom"] = 44;
    mp_display(age);
    cout << "-----------------------------------" << endl;
    // 4.查找
    auto index = age.find("jack");
    if (index == age.end())
        cout << "not found" << endl;
    else
        cout << "[" << index->first << ":" << index->second << "]" << endl;

    // count是为了找到元素的个数，可以是1或者0
    cout << age.count("steven") << "," << age.count("jjj") << endl;

    // 5. 直接使用STL的函数，查找的是key的最大值
    unordered_map<int, int> mp5({{3, 1}, {2, 9}, {1, 10}});
    cout << "maxelement: " << max_element(mp5.begin(), mp5.end())->first << "," << max_element(mp5.begin(), mp5.end())->second << endl;
}