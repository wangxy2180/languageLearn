#include <iostream>

using namespace std;

int main()
{
    char a[] = "hello";
    a[0] = 'X';
    cout << a << endl;
    char *p = "world"; // 注意p指向常量字符串
    // p[0] = 'X'; // 编译器不能发现该错误，但是在运行中会段错误
    cout << p << endl;
    cout << "---------------" << endl;

    // 下边这个可以看出两次p2的地址是不同的，因为他申请了一块内存，导致了p2存储的地址发生了变换
    int *p2;
    cout << p2 << endl;
    p2 = (int *)malloc(sizeof(int) * 2);
    cout << p2 << endl;
}
