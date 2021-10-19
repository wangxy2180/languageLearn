#include <iostream>
#include <utility>
#include <vector>
#include <string>

using namespace std;

void test(int &&a)
{
    cout << "a:" << a << endl;
}

int main()
{
    int a = 789;
    // 下边这句会出错，因为函数要求是右值引用，而我们传递的是左值
    // test(a);
    // 这句是对的
    test(789);
    // 或者将a强制转换为右值
    test(std::move(a));

    //摘自https://zh.cppreference.com/w/cpp/utility/move
    std::string str = "Hello";
    std::vector<std::string> v;
    //调用常规的拷贝构造函数，新建字符数组，拷贝数据
    v.push_back(str);
    std::cout << "After copy, str is \"" << str << ", addr is: " << &str << "\"\n";
    //调用移动构造函数，掏空str，掏空后，最好不要使用str
    v.push_back(std::move(str));
    std::cout << "After move, str is \"" << str << " , addr is: " << &str << "\"\n";
    // 地址并未发生变化
    std::cout << "The contents of the vector are \"" << v[0] << ", " << v[1] << endl;
}