#include <iostream>
#include <string>

using namespace std;

struct data1{
    // 注意，string不是基本数据类型，他的基本数据类型是
    string d;
    int a;
    double b;
    string c;//32
};

struct data2{
    string c;
    string d;
    
    int a;
    double b;
};
struct data4{

    string c;
    string d;
    
    double b;
    int a;
};

struct data3{
    int c;
    int d;
    
    int a;
    // double b;
};

struct data5{
    uint64_t a;
    int b;
};

struct DataFrame
{
    int ID;              // 成员编号
    int cmdResState;     //命令执行状态
    int state;           // 成员状态
    float power;

    float loingitudeInfo;
    float latitudeInfo;

    float velX;         // X速度
    float velY;         // Y速度
    float velZ;         // Z速度

    float anglePitch;   // 俯仰角
    float angleYaw;     // 偏航角
    float angleRoll;    // 滚转角
    float angularVelPitch;     // 俯仰角速度
    float angularVelYaw;       // 偏航角速度
    float angularVelRoll;      // 滚转角速度

    int lengthOfImageBuffer;       // 图像数据字节数
    int imageResolution;
    std::string imageBuffer;    // 图像数据

    int lengthOfLidarBuffer;       // 激光雷达数据字节数
    std::string lidarBuffer;        // 激光雷达数据

    int length;          // 数据总字节数

//取消了时间戳，接收端自己存一个吧
    int time;            // 时间戳
};

int main()
{
    cout<<sizeof(data1)<<endl; //80
    cout<<sizeof(data2)<<endl; //80
    cout<<sizeof(data3)<<endl; //12
    cout<<sizeof(data4)<<endl; //80
    cout<<sizeof(data5)<<endl; //16
    data5* adata5 = new data5;
    cout<<sizeof(adata5)<<endl; //8
    cout<<sizeof(DataFrame)<<endl; //152
    

}