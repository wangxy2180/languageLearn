#include <iostream>

using namespace std;

class MyLock
{
public:
    explicit MyLock() { cout << "locking" << endl; }
    ~MyLock() { cout << "unlock" << endl; }
};

int main()
{
    {
        // 进入作用域一开始对资源上锁
        MyLock lc;

        cout << "end of brace" << endl;
        // 在离开作用域后，lc对象被销毁，资源自动解锁
    }
    cout << "end of main" << endl;
}