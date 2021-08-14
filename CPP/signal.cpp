#include <signal.h>
#include <iostream>

using namespace std;

void stop_exec(int sig_num)
{
    cout<<"num is:"<<sig_num<<endl;
    exit(0);
}

int main()
{

    signal(SIGINT,stop_exec);

    while(1);
}