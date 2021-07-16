#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // lower_bound和upper_bound都是二分查找

    // // 在从小到大的数组里
    // lower_bound(begin,end,num):查找第一个大于或等于num的数字
    // upper_bound(begin,end,num):查找第一个大于num的数字


    // // 在从大到小的数组里
    // lower_bound(begin,end,num,greater<type>()):查找第一个小于或等于num的数字
    // upper_bound(begin,end,num,greater<type>()):查找第一个小于num的数字

    vector<int> inc={1,2,3,4,5,6,6,6,7,8};

    int pos1 = lower_bound(inc.begin(),inc.end(),6)-inc.begin();
    int pos2 = upper_bound(inc.begin(),inc.end(),6)-inc.begin();
    
    // 显然pos1的值是第一个等于6的值，upper是第一个大于6的值
    cout<<"lower_bound: "<<pos1<<endl;
    cout<<"upper_bound: "<<pos2<<endl;
    cout<<"-----------------------------------"<<endl;

    vector<int> dec={8,7,6,5,4,3,2,1};

    int pos3 = lower_bound(dec.begin(),dec.end(),6,greater<int>())-dec.begin();
    int pos4 = upper_bound(dec.begin(),dec.end(),6,greater<int>())-dec.begin();
    
    // 显然pos3的值是第一个小于等于6的值，pos4是第一个小于的值
    cout<<"lower_bound: "<<pos3<<endl;
    cout<<"upper_bound: "<<pos4<<endl;
}