#include <chrono>
#include <iostream>

using namespace std;
// https://blog.csdn.net/f110300641/article/details/82147885
int main()
{
    std::chrono::time_point<std::chrono::high_resolution_clock> zero_time;
    auto ccc =static_cast<uint64_t>(zero_time.time_since_epoch().count());
    cout<<ccc<<endl;
    auto vv =std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    cout<<vv<<endl;

}