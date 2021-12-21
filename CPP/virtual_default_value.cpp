#include <iostream>

using namespace std;

// Effective C++ 37

class Base
{
public:
    virtual void show(string inp = "Base")
    {
        cout << inp << endl;
    }
};

class Derived : public Base
{
public:
    // 不要尝试去重新定义默认参数值
    virtual void show(string inp = "Derived")
    {
        cout << inp << endl;
    }
};

int main()
{
    // 这样，它调用了Base的默认参数值，而非Derived的，
    // 因为虽然函数是动态绑定，但是参数是静态绑定的，b的参数的静态类型是Base
    Base *b = new Derived();
    b->show(); //输出：Base

    // d的参数类型是derived，所以输出是Derived
    Derived *d = new Derived();
    d->show(); //输出Derived
}