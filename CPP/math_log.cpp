#include <cmath>
#include <iostream>

#define E 2.718281828

using namespace std;

int main()
{
    // log是默认以e为底
    cout<<log(E*E)<<endl;
    cout<<log(10)<<endl;

    // log10是默认以10为底
    cout<<log10(100)<<endl;
}