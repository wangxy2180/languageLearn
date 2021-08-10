#include <iostream>
#include <Eigen/Core>

using namespace std;
using namespace Eigen;

int main()
{
    MatrixXi m(3, 3);
    m << 1, 2, 3,
         4, 5, 6,
        7, 8, 9;
    // 其实这个select，可以理解为一个if-else语句
    // select(thenMatrix, elseMatrix)
    // 对于其中所有大于5的值，取为-m，其余为m*2
    m = (m.array() >= 5).select(-m, m*2);
    cout << m << endl;
}