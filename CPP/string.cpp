#include <iostream>
#include <string>

using namespace std;
int main()
{
    string str = "abcdefghijklmn";
    str.erase(str.begin() + 5, str.end());
    cout << str << endl;
    cout << str[2] << endl;
    // 起始位置（不含）和个数
    str.erase(0, 2);
    cout << "str.earse(0,2)" << str << endl;
    str.erase(str.begin(), str.end());
    cout << str << endl;
    cout << "-----------------" << endl;

    string str2;
    str2.push_back('a');
    cout << "push_back: " << str2 << endl;
    cout << "back(): " << str2.back() << endl;
    
    // int转string
    int x=99991;
    string s3;
    s3=to_string(x);
    
}