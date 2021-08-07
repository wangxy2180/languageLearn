#include <Eigen/Core>
#include <iostream>

using namespace Eigen;

using namespace std;

int main()
{

    Matrix2d src;
    src<<1,2,1,4;

    Matrix2d r_90;
    r_90<<0,-1,1,0;

    cout<<r_90<<endl;
    cout<<src<<endl;

    Matrix2d out1;
    out1 = r_90*src;
    cout<<"out1"<<endl<<out1<<endl;


    // 转置之后，他根据原点做了中心对称
    Matrix2d out2;
    out2 = r_90.transpose()*src;
    cout<<"out2"<<endl<<out2<<endl;
    

}