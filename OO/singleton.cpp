#include <iostream>

using namespace std;

class Singleton_1
{
private:
    int a;
    Singleton_1() : a(10) {}
    // 这样的写法会有问题，即使没人用你，你也会一直存在，有些浪费，所以更好的写法如_2所示
    static Singleton_1 *instance; // = new Singleton_1();

public:
    static Singleton_1 *getInstance()
    {
        instance = new Singleton_1();
        return instance;
    }
    int getData()
    {
        return a;
    }
    ~Singleton_1() {}
};
// 如果没有这句，会未定义的引用
Singleton_1 *Singleton_1 ::instance = nullptr;

// Meyers Singleton
class Singleton_2
{
private:
    Singleton_2() {}

public:
    static Singleton_2 &getInstance()
    {
        // 只有进入这个函数，这个instance才会被创建
        static Singleton_2 instance;
        return instance;
    }
    ~Singleton_2() {}
};

int main()
{
    Singleton_1 *instance = Singleton_1::getInstance();
    cout << instance->getData() << endl;
}
