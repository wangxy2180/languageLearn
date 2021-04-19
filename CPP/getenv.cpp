#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    cout<<"PATH: "<<getenv("PATH")<<endl;
    cout<<"ROS : "<<getenv("ROS_PACKAGE_PATH")<<endl;
}