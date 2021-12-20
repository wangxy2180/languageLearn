#include <iostream>

using namespace std;

class Base
{
private:
public:
    Base() {}
    ~Base() {}
    virtual void pure_virtual() = 0;
};

// 虽然是纯虚函数，但我们对他提供了一份定义
void Base::pure_virtual()
{
    cout << "base pure_wirtual" << endl;
}

class Derived_1 : public Base
{
public:
    void pure_virtual()
    {
        cout << "derived_1 pure_wirtual" << endl;
    }
};

class Derived_2 : public Base
{
public:
    void pure_virtual()
    {
        cout << "derived_2 pure_wirtual" << endl;
        // 这里可以调用Base提供的默认纯虚函数
        Base::pure_virtual();
    }
};

int main()
{
    // Base* base=new Base(); // 错误！抽象类无法实例化
    Base *d_1 = new Derived_1();
    d_1->pure_virtual(); //调用的是自己的虚函数

    cout << "--------" << endl;

    Base *d_2 = new Derived_2();
    d_2->pure_virtual();
}