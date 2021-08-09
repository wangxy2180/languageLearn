#include <Eigen/Core>
#include <iostream>

using namespace Eigen;

using namespace std;

int main()
{
        // Array与Matrix在数据上是一样的，但是运算不一样，Matrix严格遵守矩阵运算
    // 而Array则可以提供系数级的运算，比如单个数值的平方，求和
    Array<double,2,2> aaa;
    aaa<<1,2,3,4;
    cout<<aaa.square().sum()<<endl;
    cout<<"-----------------"<<endl;

}