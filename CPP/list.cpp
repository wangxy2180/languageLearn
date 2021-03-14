#include <iostream>
#include <list>

using namespace std;

template <typename T>
void list_print(list<T> list_p);

// 如果你需要大量的插入和删除，而不关心随机存取，则应使用list
int main()
{
    // 1.构造方法
    list<int> list_test(2,3);
    cout<<"constructor: ";
    list_print(list_test);
    list<int> list_1 = {1, 2, 3};
    // 2.支持前后push和pop
    list_1.push_back(4);
    list_1.push_front(0);
    list_print(list_1);
    list_1.pop_back();
    list_1.pop_front();
    list_print(list_1);

    // 2.获取头尾元素
    cout << "front: " << list_1.front() << ", back: " << list_1.back() << endl;

    // 3.逆置与排序,sort是按升序排序
    list_1.reverse();
    cout << "reverse: ";
    list_print(list_1);

    list_1.sort();
    cout << "sort: ";
    list_print(list_1);

    // 4.插入与删除
    list_1.insert(++list_1.begin(), 9999);
    list_1.insert(++list_1.begin(), 999999);
    list_1.erase(--list_1.end());
    for(auto i = list_1.begin();i!=list_1.end();++i)
    {
        if(*i==9999)list_1.erase(i);
    }
    cout<<"insert and erase: ";
    list_print(list_1);
}

template <typename T>
void list_print(list<T> list_p)
{
    for (auto k : list_p)
        cout << k << ", ";
    cout << endl;
}