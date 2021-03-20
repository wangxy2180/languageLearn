#include <iostream>
#include <stdlib.h>
#include <typeinfo>

using namespace std;

int main()
{
    // 1.string to integer
    int a = atoi("123");
    // 注意这个atoi，如果是string类型，需要转为char*
    string str_a = "123";
    atoi(str_a.c_str());
    cout<<typeid(a).name()<<endl;
    // 为啥呢
    int ccc = 8;
    cout<<isdigit(a)<<endl;
}