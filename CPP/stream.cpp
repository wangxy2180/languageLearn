#include <sstream>
#include <iostream>

using namespace std;

int main()
{
    // 字符串流
    stringstream ss;
    ss<<"hhhhh"<<1.22<<", "<<11111<<endl;
    cout<<ss.str().c_str();

}