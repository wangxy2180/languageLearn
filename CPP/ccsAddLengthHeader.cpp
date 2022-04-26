#include <iostream>
#include <string>
#include <math.h>

// 8位16进制数，最大表示4G
#define HEADER_LENGTH 8

using namespace std;

// 10进制int转16进制字符串
string convertDecInt2HexStr(int decInt)
{
    int x;
    string hex;
    string ret;
    while (decInt != 0)
    {
        x = decInt % 16;
        if (x < 10)
        {
            hex = x + '0';
        }
        else
        {
            hex = x + 'A' - 10;
        }
        ret = hex + ret;
        decInt = decInt / 16;
    }
    string prefixZero(HEADER_LENGTH - ret.size(), '0');
    ret = prefixZero + ret;

    return ret;
}

int convertHexStr2DecInt(string hexStr)
{
    int ret=0;
    int hexBase = 1;
    for (auto i = hexStr.rbegin(); i != hexStr.rend(); ++i)
    {
        if ('0' <= *i && *i <= '9')
            ret += (*i - '0') * hexBase;
        else
            ret += (*i - 'A' + 10) * hexBase;

        hexBase *= 16;
    }
    cout << "十进制:" << ret << endl;
    return ret;
}

void addLengthHeader(string &inputOutput)
{
    // int dataLengthInt = inputOutput.size();
    int dataLengthInt=100022200;
    string dataLengthStr = convertDecInt2HexStr(dataLengthInt);
    cout << dataLengthStr << endl;
    inputOutput = dataLengthStr + inputOutput;

    int len = convertHexStr2DecInt(dataLengthStr);
    cout << "原始10进制数据：" << dataLengthInt << endl;
    cout << "10进制转换回来：" << len << endl;
}

int main()
{
    string a = "1234567890";
    addLengthHeader(a);
    cout << a << endl;
}