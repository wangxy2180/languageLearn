#include<iostream>
using namespace std;

struct test_s{
    int i;
    char c;
};

int main()
{
    test_s a;
    a.i=1;
    a.c='c';

    test_s b;
    b=a;
    cout<<b.i<<","<<b.c<<endl;
    a.i=3;
    cout<<b.i<<","<<b.c<<endl;

}