#include <iostream>

using namespace std;

int& test(int& input)
{
    return input;
}

int main()
{
    int a = 0;
    // 如果你用一个引用类型去接收返回的引用类型，那么他就是可修改的，最终ab的值是相等
    int& b = test(a);
    b=9;
    cout<<"a="<<a<<endl<<"b="<<b<<endl;
    
}