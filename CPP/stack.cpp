#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<int> s1;

    // 压栈
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);

    // 出栈
    // 输出栈顶的内容
    cout<<s1.top()<<endl;
    // 把栈顶的内容删除，返回值为void
    s1.pop();
    cout<<s1.top()<<endl;
}