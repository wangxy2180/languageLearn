#include <iostream>
#include <initializer_list>

using namespace std;

void print_init_list(initializer_list<string> li)
{
    for (auto k : li)
        cout << k << ", ";
    cout << endl;
}

int main()
{
    // initializer_list用于数量未知，但类型全都一样的初始化列表
    print_init_list({"jack","tom","peter","steven"});
}