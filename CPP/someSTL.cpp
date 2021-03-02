#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    // 1.is_sort()判断是否已经排好序,返回bool类型，默认升序检查
    vector<int> a = {1,2,3,4,5,6,7,4,3};
    cout<<is_sorted(a.begin(),a.begin()+5)<<endl;
    cout<<is_sorted(a.begin(),a.end())<<endl;
    cout<<is_sorted(a.begin(),a.begin()+5,greater<int>())<<endl;//改为降序检查
    
}