#include <iostream>
using namespace std;

class ClassSize
{
private:
    int a;
    int b;
    double c;
    int d;
    char e;

public:
    int seta(int a)
    {
        this->a = a;
    }
};

int main()
{
    cout << sizeof(ClassSize) << endl;
    // 输出为24，因为内存对齐的关系，函数并不占用类的大小
}
