#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_it(int a)
{
    cout<<"print_it:"<<a<<endl;
}

int main()
{
    // 同样支持lambda函数
    vector<int> a{1,2,3,4,5,6,7,8};
    for_each(a.begin(),a.end(),print_it);

}