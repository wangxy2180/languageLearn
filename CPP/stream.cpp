#include <sstream>
#include<fstream>
#include <iostream>
#include <vector>

using namespace std;

// 可选的将输出内容输出到屏幕上或者文件中
void display(vector<int> vec, ostream& os = cout)
{
    for(auto k : vec)
    {
        os<<k<<endl;
    }
}

int main()
{
    // 字符串流
    stringstream ss;
    ss<<"hhhhh"<<1.22<<", "<<11111<<endl;
    cout<<ss.str().c_str();

    vector<int> a{1,2,3,4,6,7};
    // 输出到屏幕
    display(a);

    // 输出到文件
    ofstream outfile("stream.txt");
    if(outfile)display(a,outfile);

}