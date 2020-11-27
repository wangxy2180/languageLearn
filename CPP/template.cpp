#include<iostream>

using namespace std;

template <typename T>
int compare(const T v1, const T v2)
{
    return v1<v2;
}

int main()
{
    cout<<"result is:"<<compare(3,2)<<endl;
}
