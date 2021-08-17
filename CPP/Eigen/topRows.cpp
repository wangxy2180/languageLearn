#include <Eigen/Core>
#include <iostream>

using namespace Eigen;

using namespace std;

int main()
{
    
    Array<double,4,1> tr;
    tr<<1,2,3,4;
    cout<<tr<<endl;
    cout<<"---------------------"<<endl;

    
    // 让最上边的3个值等于最后边的3个值，两个size必须一样
    tr.template topRows<4 - 1>() = tr.template bottomRows<4 - 1>();
    cout<<tr<<endl;
    cout<<"sum "<<tr.topRows<4-2>().sum()<<endl;

        // 一定要注意最核心的那两个template，像下边这样写会造成歧义
    // topRows<4 - 1>() = bottomRows<4 - 1>();
    cout<<"---------------------"<<endl;
    // 或者写成这样
    tr.topRows(3) = tr.bottomRows(3);
        // tr(3)=5;
    cout<<tr<<endl;

    cout<<"---------------------"<<endl;
    // 或者进行一个区间的选取
    Array<double,4,1> mr;
    mr<<1,2,3,4;
    // 0是开始行数，3是size
    cout<<mr.middleRows(0,3)<<endl;
    cout<<"xxx"<<endl;
    cout<<mr.middleRows<3>(1)<<endl;




}