#include <iostream>
#include <Eigen/Core>

using namespace std;
using namespace Eigen;

int main()
{
    MatrixXf m(4,4);
    m<< 1,2,3,4,
        5,6,7,8,
        9,10,11,12,
        13,14,15,16;
    cout<<"Block in the middle"<<endl;
    // size和开始位置
    cout<<m.block<3,3>(1,1)<<endl<<endl;
    for(int i = 1;i <= 3;++i)
    {
        // 分别是开始，结束(不含)
        cout<<"Block of size "<<i<<"x"<<i<<endl;
        cout<<m.block(0,0,i,i)<<endl<<endl;
    }
}
