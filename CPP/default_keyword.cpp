#include <iostream>
using namespace std;

class Default_test
{
private:
public:
    // 我也不知道有啥用，他们说如果不加这句，会报错，可实际上我的也没报错啊
    Default_test() = default;
    ~Default_test();

    // 当设置为delete后，你会发现代码自动补全里边没有了这个函数
    void test_delete()=delete;
    // void test_delete();
};

int main()
{
    Default_test *dt = new Default_test();
}