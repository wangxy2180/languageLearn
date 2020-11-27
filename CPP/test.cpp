#include <iostream>
using namespace std;
int main()
{

    int a = 10;
    int* p;
    int *q;
cout<<"a "<<&a<<endl;

        cout<<"p："<<p<<endl;
    cout<<"*p："<<*p<<endl;
    cout<<"q："<<q<<endl;
    cout<<"*q："<<*q<<endl;
    cout<<"==================="<<endl;
    p=&a;
    *q=a;

    cout<<"p："<<p<<endl;
    cout<<"*p："<<*p<<endl;
    cout<<"q："<<q<<endl;
    cout<<"*q："<<*q<<endl;
    cout<<"==================="<<endl;

    a = 12;
    cout<<"p："<<p<<endl;
    cout<<"*p："<<*p<<endl;
    cout<<"q："<<q<<endl;
    cout<<"*q："<<*q<<endl;
    cout<<"==================="<<endl;


}