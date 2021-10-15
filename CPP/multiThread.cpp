#include <iostream>
#include <thread>

using namespace std;

void output(int i)
{
    cout<<i<<endl;
}

int main()
{
    for(int i = 0;i<5;++i)
    {
        std::thread t(output,i);
        t.detach();
    }

    return 0;

}