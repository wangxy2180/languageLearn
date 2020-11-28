#include <iostream>
#include <string>
// 在这里定义NDEBUG，会影响cassert里生成的代码 assert不会被执行
// #define NDEBUG

#include <cassert>
using std::cout;
using std::endl;
using std::string;

// 一般来说，内联函数性能好一点，对于这种
// 小功能，频繁调用，流程简单的函数，可以用内联函数，当然，编译器可以选择忽略
// 定义在类内部的函数，一般是隐式inline
inline const std::string &shorterString(const string &a, const string &b)
{
    return a.size() > b.size() ? b : a;
}

int main()
{
    std::string a("abcdefg");
    std::string b("abcdefghijk");
    cout << shorterString(a, b) << endl;
    // 检查不可能发生的条件，作为一种调试手段
    assert(0);
    cout << "after assert" << endl;
#ifdef NDEBUG
    cout << "in file:" << __FILE__ << endl
         << "function:" << __func__ << endl
         << "line:" << __LINE__ << endl
         << "Date:" << __DATE__ << endl
         << "time:" << __TIME__ << endl;
#endif
}