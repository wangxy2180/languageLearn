#include <iostream>

class constMenFunc
{
private:
    int a, b;

public:
    constMenFunc(int a = 3, int b = 4) : a(a), b(b) {}

    // 对于不会发生修改的程序，一定要加const，这样当你尝试进行修改时，编译器会报错
    int get_a()
    {
        a = 3;
        return a;
    }
    int get_b() const { return b; }
    // 下边这个函数会报错的，因为不能修改
    // int get_b() const
    // {
    //     b = 4;
    //     return b;
    // }
};

int main()
{
    constMenFunc p(1, 2);
    std::cout << p.get_a();
    std::cout << p.get_b();

    // 还有一种情况，下边这个是告知编译器，我这个9 10 不能动哦
    // 你会发现此时你只能调用q.get_b()，无法调用q.get_a()
    // 因为q.get_a()可能会修改值，而使用者要求的是不能改
    const constMenFunc q(9,10);
    // 下边这个会报错
    // std::cout<<q.get_a();
    // 正确
    std::cout<<q.get_b();
}
