#include <iostream>

using namespace std;

struct test{
    int a;
    int b;
    float c;

    // test(int a, int b, float c):a(a),b(b),c(c){}

    // 这里必须是友元，否则会报错 太多参数
    // 要不然就把他写在类外边
    // friend std::ostream& 
    // operator<<(std::ostream &os, const test &t)
    // {
    //     return os<<"test is:"<<t.a<<", "<<t.b<<", "<<t.c<<endl;
    // }

    friend ostream& operator<<(ostream &os, const test& t);
};

std::ostream& 
operator<<(std::ostream &os, const test &t)
{
    return os<<"test is:"<<t.a<<", "<<t.b<<", "<<t.c<<endl;
}

// 这种返回的写法以前没见过，下边两个是等价的
auto return_test(int a, int b, float c)->test{ return {.a=a,.b=b,.c=c};}
auto return_test2(int a, int b, float c)->test{ return test{.a=a,.b=b,.c=c};}

int main()
{
    auto kk=return_test(1,2,3.3);
    cout<<kk<<endl;

    auto kkk=return_test(9,11,7.7);
    cout<<kkk<<endl;
}
