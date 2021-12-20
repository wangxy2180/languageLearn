#include <iostream>
#include<iosfwd>

using namespace std;

class MyBase
{
private:
public:
    MyBase() {}
    ~MyBase() {}

    virtual void print_info() const
    {
        cout << "MyBase" << endl;
        ;
    }
};

class Derived : public MyBase
{

public:
    Derived() {}
    ~Derived() {}

    void print_info() const
    {
        cout << "MyDerived" << endl;
        ;
    }
};

void passByValSlice(MyBase v)
{
    // 这里是pass-by-value，发生了切割，v本质上还是一个base，不管你传进来的是啥，他都是base
    v.print_info();
}

void passByRefSlice(const MyBase &r)
{
    // 这里是pass-by-reference，没有发生切割，r本质上是derived，你传进来的是啥，他就表示为啥
    r.print_info();
}

int main()
{
    Derived der;
    passByValSlice(der);
    passByRefSlice(der);
}