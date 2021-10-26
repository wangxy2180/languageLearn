#include <iostream>
// #include <time.h>
#include <unistd.h>
using namespace std;

void eat()
{
    cout << "eat" << endl;
}

void sell()
{
    cout << "sell" << endl;
}

// 制作油条
void make_youtiao(int t, void (*act)())
{
    sleep(t);
    cout<<"youtiao!"<<endl;
    act();
}

int main()
{
    // 采用下边这样的方式，就可以让他做完油条后，自主选择是卖掉还是吃掉了
    make_youtiao(2, eat);
    make_youtiao(2, sell);
    cout<<"----ok----"<<endl;
    // 但是上边这样有个问题，就是他还是阻塞执行的，没有体现出优势啊
    // 下边这样可以创建一个线程去异步执行
    // todo
}