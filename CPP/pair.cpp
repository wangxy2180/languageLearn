#include <iostream>
#include <tuple>

using namespace std;

pair<string, int> get_person();

int main()
{
    pair<int, int> p1;
    p1.first = 1;
    p1.second = 333;
    cout << p1.first << "," << p1.second << endl;

    // 1.构造方式
    pair<int, int> p2(6, 9);
    // 这个make_pair一般可以用作函数返回pair类型时使用，这样就不需要创建pair类型的变量了
    p2 = make_pair(666, 999);
    // 只是copy值，不存在指针，所以修改一个的值，另一个不会被修改
    pair<int, int> p3 = p2;
    p3.first = 1;
    cout << "= copy construct, value not pointer: " << p2.first << endl;
// 大规模初始化时要这样写
    pair<int, string> mp[] = {
        {1, "I"}, {2, "II"}, {3, "III"}, {4, "IV"}, {5, "V"}, {9, "IX"}, {10, "X"}, {40, "XL"}, {50, "L"}, {90, "XC"}, {100, "C"}, {400, "CD"}, {500, "D"}, {900, "CM"}, {1000, "M"}};

    // 还可以用tie函数，不过这就是一种高级的用法了，我也不懂,需要include<tuple>
    // C++函数：std::tie 详解https://www.cnblogs.com/RioTian/p/14076214.html
    string name;
    int age;
    std::tie(name, age) = get_person();
    cout << "name: " << name << ",age: " << age << endl;
}

pair<string, int> get_person()
{
    // 可以用make_pair构造返回值
    return make_pair("jack", 26);
}