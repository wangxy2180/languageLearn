// 编译器默认带有拷贝构造和拷贝赋值，但是对于带有指针的，不建议使用
// 因为会让两个类中的指针指向同一处地方，这并不是真正的拷贝
// 所以如果你的类里边带指针，那么就不能用编译器给的默认版本

// 只要你的类带有指针，就一定要写拷贝构造和拷贝赋值函数！！！还有析构函数，这三个叫做big three
// copy constructor and copy assign operator

#include <iostream>
#include <cstring>
class MyString
{
private:
    char *m_data;

public:
    // 给他一个默认值
    MyString(const char *cstr = 0);

    // 只要你的类带有指针，就必须写这两个函数
    // 这个函数接收自己，叫 拷贝构造！！！
    MyString(const MyString &str);
    // 这个叫做拷贝赋值！！！
    MyString &operator=(const MyString &str);
    // 析构函数
    ~MyString();

    char *get_c_str() const { return m_data; }
};

inline MyString::MyString(const char *cstr = 0)
{
    if (cstr)
    {
        m_data = new char[strlen(cstr) + 1];
        strcpy(m_data, cstr);
    }
    else
    {
        // 未指定初值
        m_data = new char[1];
        *m_data = '\0';
    }
}

inline MyString::MyString(const MyString &str)
{
    // 因为这里互为友元，所以可以访问private
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
}

// 注意，下边这个函数的两个“&”含义是不同的，参数列表的叫引用，函数体中的叫取地址
inline MyString &MyString::operator=(const MyString &str)
{
    // 看看两个指针指的是不是同一块东西
    // 这两行一定要写，不只是影响效率，如果不写可能会出错(被拷贝的内容被删除了)
    if (this == &str)
        return *this;
    // 如果被赋值对象有内容，则需要先清空再拷贝
    delete[] m_data;
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
    return *this;
}

inline std::ostream &operator<<(std::ostream &os, MyString &str)
{
    os << str.get_c_str();
    return os;
}

inline MyString::~MyString()
{
    // 因为你有new的动态分配内存，所以要清理一下
    delete[] m_data;
}
