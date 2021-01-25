#include <iostream>
class Account
{
private:
    double data;

public:
    static double m_rate;
    // 静态函数没有this pointer，只能处理静态数据
    static void set_rate(const double &x) { m_rate = x; }
    Account(/* args */);
    ~Account();
    void set_data() { data = 10; }
};
// 一定要在class的外边对静态数据干这样的事情。
double Account::m_rate = 8.0;

Account::Account(/* args */)
{
}

Account::~Account()
{
}

int main()
{
    // 静态函数可以没有object直接调用，或者直接通过classname调用，
    // 非静态只能通过对象
    Account::set_rate(5.0);
    Account b;
    std::cout << b.m_rate << std::endl;

    Account a;
    std::cout << a.m_rate << std::endl;
    // 静态函数，虽然是通过object调用的，但是没有隐含的this了
    a.set_rate(7.0);
    std::cout << b.m_rate << std::endl;

    // 这两个的输出是一样的，证明这个静态只有一份，一个改了，所有的都改了


    // 下边的就不能这么用
    // Account::set_data();
}