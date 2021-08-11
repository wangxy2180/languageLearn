#include <iostream>
#include <Eigen/Core>

using namespace std;
using namespace Eigen;

int main()
{
        
    Array<double,4,1> tr;
    tr<<1,2,3,4;
    cout<<tr<<endl;
    cout<<"---------------------"<<endl;

    // 这个和topRows是一样的东西，只不过一个管横着，一个管竖着
    cout<<tr.leftCols<1>()<<endl;
}