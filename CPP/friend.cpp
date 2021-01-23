#include <iostream>
// 相同class的object互为友元
class friendTest
{
public:
    int get_a() const { return a; }
    int get_b() const { return b; }
    friendTest(int a = 1, int b = 2) : a(a), b(b) {}
    // a,b是private的，但是因为同一个类的对象互为友元，所以可以访问；
    int add(friendTest &ft)
    {
        return ft.a + ft.b;
    }

private:
    int a, b;
};

int main()
{
    friendTest a(3, 4);
    friendTest b;

    std::cout << b.add(a);
}