#include <iostream>

using namespace std;

class Singleton
{
private:
    int a;
    Singleton() : a(10) {}
    static Singleton *instance; // = new Singleton();

public:
    static Singleton *getInstance()
    {
        instance = new Singleton();
        return instance;
    }
    int getData()
    {
        return a;
    }
    ~Singleton() {}
};
// 如果没有这句，会未定义的引用
Singleton *Singleton ::instance = nullptr;

int main()
{
    Singleton *instance = Singleton::getInstance();
    cout << instance->getData() << endl;
}
