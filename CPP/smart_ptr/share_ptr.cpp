#include<iostream>
#include <memory>
#include <vector>


using namespace std;

int main()
{
    // <>中表名指针可知指向的数据类型
    // 指向string的指针
    // 一定要注意，智能指针的但运算符和剪头运算符是不一样的！！！
    shared_ptr<string> p1; 
    
    // 一个指向值为42的int的shared_ptr
    shared_ptr<int> p2=make_shared<int>(42);
    shared_ptr<int> p22=make_shared<int>(422);
    // 下边这条语句被执行后，p2原本指向的对象就会被自动释放
    p2=p22;

    // 或者一般直接使用auto的方法，让他自动推断智能指针的类型
    vector<int> vec{1,2,3};
    auto p3= make_shared<vector<int>>(vec);
    // 构造p4，此时p3和p4指向同一个对象，也就是说这个对象有两个引用者
    // 可以通过unique判断是否是唯一的引用
    cout<<p3.unique()<<", ";
    auto p4(p3);
    cout<<p3.unique();
    
}