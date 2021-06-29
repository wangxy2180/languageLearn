#include<iostream>

using namespace std;

void test(int&& a)
{
    cout<<"a:"<<a<<endl;
}

int main()
{
    int a= 789;
    // 下边这句会出错，因为函数要求是右值引用，而我们传递的是左值
    // test(a);
    // 这句是对的
    test(789);
    // 或者将a强制转换为右值
    test(std::move(a));
}