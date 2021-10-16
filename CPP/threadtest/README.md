首先，不建议使用单纯的c++文件去做多线程，一定要写一个cmake

如果是单纯的C++文件，记的要加上 -lpthread


1. 01_simple_case: 一个简单的小case
    `g++ 01_simple_case.cpp -o 01_simple_case -lpthread`
    join:子进程和主进程同在，主线程得等我执行完了，才能结束，其实在这里会按顺序执行，也就是会阻塞式的执行