#include <iostream>
#include <thread>

// g++ 01_simple_case.cpp -o 01_simple_case -lpthread

using namespace std;

void output(string t, int i)
{
    for (int i = 0; i < 10; ++i)
    {
        cout << t << ":" << i << endl;
    }
    // cout<<i<<endl;
}

void thread_join()
{
    cout << "thread_join-1" << endl;
    cout << "thread_join-2" << endl;
    cout << "thread_join-3" << endl;

    thread t1(output, "join", 1);
    cout << "thread_join-4" << endl;
    cout << "thread_join-5" << endl;
    cout << "thread_join-6" << endl;

    if (t1.joinable())
        t1.join();

    cout << "thread_join-7" << endl;
    cout << "thread_join-8" << endl;
    cout << "thread_join-9" << endl;
    cout << "---------- join end ----------" << endl;
}

void thread_detach()
{
    // 这里边的程序可以看到，他是无序输出的，甚至先执行完了正常的cout语句，然后才开始执行t1
    cout << "thread_detach-1" << endl;
    cout << "thread_detach-2" << endl;
    cout << "thread_detach-3" << endl;

    thread t1(output, "detach", 1);
    cout << "thread_detach-4" << endl;
    cout << "thread_detach-5" << endl;
    cout << "thread_detach-6" << endl;
    t1.detach();

    cout << "thread_detach-7" << endl;
    cout << "thread_detach-8" << endl;
    cout << "thread_detach-9" << endl;
    cout << "---------- detach end ----------" << endl;
}

int main()
{
    thread_join();
    thread_detach();
    cout << "main-1" << endl;
    cout << "main-2" << endl;
    cout << "main-3" << endl;
    // thread t1(output, "join", 1);
    // thread t2(output,"detach",1);
    cout << "main-4" << endl;
    cout << "main-5" << endl;
    cout << "main-6" << endl;

    // if (t1.joinable())
    //     t1.join();
    cout << "main-7" << endl;
    cout << "main-8" << endl;
    cout << "main-9" << endl;

    cout << "main end" << endl;
    // 在这后边输出的语句，都是交给操作系统后台执行了
    return 0;
}