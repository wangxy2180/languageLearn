/**
 * 这里还是不懂啊
*/

#include <iostream>

class TestClass
{
private:
    /* data */
public:
    // 这个就是默认构造函数，啥都没有
    TestClass(/* args */);

    TestClass(int a_in) : a(a_in)
    {
        // a=a_in;
        std::cout << "a:" << a << std::endl;
    }
    ~TestClass();

    int a;
};

TestClass::TestClass(/* args */)
{
}

TestClass::~TestClass()
{
}

int main()
{
    TestClass test1();
    TestClass test2;
    TestClass *test3 = new TestClass();

    // test1.a;    //这种写法错误！你定义的test1()是一个函数
    // 下边这两种写法是正确的
    test2.a;
    test3->a;

    // 这种是可以的，因为它有参数列表
    TestClass test4(1);
}