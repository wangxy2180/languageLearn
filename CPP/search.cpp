#include <algorithm>
#include <iostream>
#include <vector>

// C++居然提供了内置的查找函数

int main()
{
    std::vector<int> a({1, 2, 3, 4, 5, 6, 7, 8});
    // 注意，这个binary_search只能告诉我们他是否在列表中
    auto ret = std::binary_search(a.begin(), a.end(), 799);
    std::cout<<"binary_search: "<<ret<<std::endl;

    // 如果你需要知道下标，则需要使用lower_bound, upper_bound等
    // 这两种方法都是使用二分查找在一个排好序的列表中查找
}