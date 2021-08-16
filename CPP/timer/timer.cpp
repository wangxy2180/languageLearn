#include "stopWatch.h"
// #include "fast_corner.h"
#include <iostream>
#include <unistd.h>

// g++ -std=c++14
// fast_corner的有错呢

using namespace std;

int main()
{
    
    Stopwatch timer_1;
    timer_1.tic();
    // 1000 is us
    usleep(1000000);
    auto elapsed = timer_1.toc();
    cout<<"elapsed: "<<elapsed<<endl;


    // utils::time::Timer<std::chrono::nanoseconds> timer_2;
    // timer_2.tic();
    // // 1000 is us
    // usleep(1000000);
    // auto elapsed_2 = timer_2.toc();
    // cout<<"elapsed_2: "<<elapsed_2<<endl;


}