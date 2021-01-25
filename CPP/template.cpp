#include <iostream>

using namespace std;

// 模板类
template <typename T>
class MyData
{
public:
    MyData(T a = 0, T b = 0) : a(a), b(b) {}
    T get_a() const { return a; }
    T get_b() const { return b; }

    bool operator<(const MyData &right) const
    {
        // 重写MyData的小于写法，只有都小于时，才判定为小于
        if (a < right.a && b < right.b)
            return true;
        else
            return false;
    }

private:
    T a, b;
};

inline ostream &operator<<(ostream &os, const MyData<int> &m)
{
    os << "(" << m.get_a() << "," << m.get_b() << ")";
    return os;
}

// 模版函数
// typename 和 class两个关键字相同
template <class T>
T my_min(const T &v1, const T &v2)
{
    return v1 < v2 ? v1 : v2;
}

int main()
{
    // 注意：模板函数会自动推导参数(argument deduction)的类型，所以无需指定参数类型
    cout << "result is:" << my_min<int>(3, 2) << endl;
    cout << "result is:" << my_min(3, 2) << endl;

    MyData<int> a(1, 2);
    MyData<int> b(2, 3);
    cout << "MyMin is :" << my_min<MyData<int>>(a, b) << endl;
    cout << "MyMin is :" << my_min(a, b) << endl;
    
    // 因为重写了小于号<，所以可以直接调用标准库中的min
    // C++ STL中的算法都是函数模版
    cout << "Min is :" << min(a, b) << endl;
}
