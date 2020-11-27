#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

bool inorder(char &a,char &b)
{
    // return a.compare(b)<0;
    // return a>b;
    return 1;
}
int main()
{
    string a("acbedf");
    // string a;
    // cbegin consr begin
    for (auto i=a.cbegin();i!=a.cend();i++)
    {
        cout<<"string "<<*i<<endl;
    }
    if(a.begin()!=a.end())
    {
        // 迭代器的类型这样定义
        string::iterator i,j;
        i=a.begin();
        j=a.end()-1;
        *i=toupper(*i);
        *j=toupper(*j);
        auto h=j-i;

        cout<<"max_size"<<a.max_size()<<endl;
        cout<<"h"<<h<<endl;
    }
    bool bb='b'<'b';
    cout<<bb<<endl;

    cout<<"str :"<<a<<endl;
    sort(a.begin(),a.end(), inorder);
    cout<<"sort:"<<a<<endl;

}