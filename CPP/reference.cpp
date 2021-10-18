#include <iostream>

using namespace std;

/**
 * 一个被广泛认同的说法 
 * 可以放在等号左侧的，就是左值，否则就是右值
 * 可以取地址的，有名字的，非临时的，就是左值
 * 不能取地址的，没有名字的，临时的，就是右值；如函数的返回值，立即数
 */

void test(int&& a);

int main()
{
    // 左值引用 ,和指针是一样的
    // int &invalid=10;
    // 上边这个是非法的，因为他无法对立即数取地址
    const int &valid = 10;
    // 上边这个是合法的，它相当于创建了一个临时变量存储，但是没有任何意义，因为你修改不了他的值

    int ival = 1024;
    int &refval = ival;
    // 这里两个变量指向同一个地址，修改同一个值
    cout << "refval:" << refval << "," << endl;
    refval = 1000;
    cout << "ival  :" << ival << ","<<endl;;
    // 地址是
    cout << "address:" << endl;
    cout << "refval:" << &refval << "," << endl
         << "ival  :" << &ival << "," << endl;
    // 用指针做同样的事情
    int *p;
    p = &ival;
    *p = 2000;
    cout << ival << endl;
    cout << "==========================================" << endl;
    // 右值引用 https://zhuanlan.zhihu.com/p/97128024
    // 右值引用只能被绑定在一个将要被销毁的对象上
    int i = 10;
    // int &&rr=i;
    // 上边这句编译时会报错，不能绑定右值引用int&&到左值int
    // 但，可以通过move函数强行绑定右值引用到左值、
    int &&rr2 = std::move(i);
    cout << rr2 << endl;

    int &&rr = i * 10;
    cout << rr << endl;

    cout << "==========================================" << endl;

    int a= 789;
    // 下边这句会出错，因为函数要求是右值引用，而我们传递的是左值
    // test(a);
    // 这句是对的
    test(789);

    cout << "==========================================" << endl;
    cout << "==========================================" << endl;
}

void test_const_ref(const int &input)
{
    // 下边的报错，因为input是const的
    // input=10;

}

void test(int&& a)
{
    cout<<"a:"<<a<<endl;
}