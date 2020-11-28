#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> i_vec;
    int i;
    cout << "input" << endl;
    // cin>>a;
    while (cin >> i)
    {
        i_vec.push_back(i);
        cout << "input is :" << i << endl;
    }
    // for(int i;cin>>i;)i_vec.push_back(i);

    for (auto k : i_vec)
    {
        cout << k;
    }
}