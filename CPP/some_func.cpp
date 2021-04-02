#include <iostream>

using namespace std;

int main()
{
    // 大小写转换、
    string s = "ABCDEFGhijk";
    string s_1;
    for(auto k : s)
    {
        s_1+=tolower(k);
    }
    cout<<s_1<<endl;

    // 判断是否是数字和字母
    cout<<isalnum('c')<<", ";
    cout<<isalnum('1')<<", ";
    cout<<isalnum('.')<<", "<<endl;

}