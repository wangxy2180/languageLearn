#include <iostream>

using namespace std;

// NVI设计 Effective C++ 35
// 子类决定干啥，父类决定何时调用

// Effective C++ 37
// virtual_default_value.cpp

class Base
{
public:
    // NVI设计，避免重写静态绑定的东西
    void show(string inp = "Base")
    {
        myshow(inp);
    }

private:
    // 真正要完成工作在这里
    virtual void myshow(string inp)
    {

        cout << "Based  : " << inp << endl;
    }
};

class Derived : public Base
{
public:
private:
    // 不需要指定函数默认参数
    virtual void myshow(string inp)
    {
        cout << "Derived: " << inp << endl;
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