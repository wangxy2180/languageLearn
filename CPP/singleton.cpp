// 单例模式，

class A
{
    // 这种写法不是最完美的，如果外接没有用到A的地方，A也会一直存在
private:
    A();
    A(const A &rhs);
    static A a;

    int data;

public:
    static A &getInstance() { return a; }
    void setup() {}
};

// 更好的写法
// Meyers Singletom
class B
{
private:
    B();
    B(const B &rhs);
public:
    static B& getInstance(){}
    void setup(){}
};

B& B::getInstance()
{
    // 只有当调用他时才会创建对象
    // 并且永远只有这一份
    static B b;
    return b;
}

B::B(/* args */)
{
}

B::~B()
{
}

int main()
{
    // 因为getInstance是静态的，所以只有一份，又因为A的构造函数是private的，所以只能通过这个函数去创建
    // 因此该class只有一个对象，并且该对象也是静态的，他一直都存在着
    // 也就是外界不能创造它，只能去获得他
    A::getInstance().setup();

    B::getInstance().setup();
}