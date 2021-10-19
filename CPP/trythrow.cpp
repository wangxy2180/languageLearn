#include <iostream>
#include <stdexcept>

using namespace std;

void test(int a)
{
    try
    {
        if (a == 1)
        {
            throw -1;
        }
    }
    catch (...)
    {
        std::cerr << "throw test:" << '\n';
    }
    cout << "test end" << endl;
}

int main()
{
    int a = 2;
    // int b = 2;

    try
    {
        if (a == 0)
        {
            throw -1;
        }
        if (a == 1)
        {
            throw std::runtime_error("a==1");
        }
        if (a == 2)
        {
            throw std::exception();
        }
        if (a == 3)
        {
            throw 0.1;
        }
    }
    catch (int e)
    {
        // 只捕获int型的异常
        std::cerr << "int error !" << std::endl;
    }
    catch (const std::runtime_error &e)
    {
        // 只捕获runtime_error
        std::cerr << "runtime_error !" << std::endl;
        std::cerr << e.what() << '\n';
    }
    catch (const std::exception &e)
    {
        // 基本所有的异常都能被他捕获
        std::cerr << "exception_error !" << std::endl;
        std::cerr << e.what() << '\n';
    }
    catch (...)
    {
        // 以防万一的一句
        std::cerr << "any type expection" << std::endl;
    }
    test(1);
    cout << "main end" << endl;
}