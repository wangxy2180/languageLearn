#include <iostream>

using namespace std;

class Father
{
public:
    Father()
    {
        cout << "cotr Father" << endl;
    }
    virtual ~Father()
    {
        cout << "decotr Father" << endl;
    }
};

class Son : public Father
{
public:
    Son()
    {
        cout << "cotr Son" << endl;
    }
    ~Son()
    {
        cout << "decotr Son" << endl;
    }
};

int main()
{
    // 这个会析构Father，但是不会析构Son；
    // 你必须将父类析构函数设置为virtual，他才会析构子类的
    Father *f = new Son();
    delete f;
    cout << "-----------------" << endl;
    // 这个会析构Father和Son
    Son *s = new Son();
    delete s;
}