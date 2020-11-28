#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    // 使用boolalpha，让他输出true和false，使用noboolalpha取消
    cout << "true or false:" << true << "," << false << endl
         << boolalpha << "true or false:" << true << "," << false << endl;
    cout << true << noboolalpha << " " << true << endl;
    cout << "=====================================================" << endl;

    string a = "1234567890";
    string b = "1234567";
    string c = "1234";
    // left 左对齐，right 右对齐 setw(n)在他后边输出的占n个宽度
    cout << left << setw(12) << a << "next col" << endl
         << setw(12) << b << "next col" << endl
         << setw(12) << c << "next col" << endl;
    // setfill 填充
    cout << setfill('#') << left << setw(12) << a << "next col" << endl
         << setw(12) << b << "next col" << endl
         << setw(12) << c << "next col" << endl
         << setfill(' ');
    cout << "=====================================================" << endl;

    // 打印浮点数精度
    cout << "Precision:" << cout.precision() << ".value:" << sqrt(2.0) << endl;
    cout.precision(12);
    cout << "Precision:" << cout.precision() << ".value:" << sqrt(2.0) << endl;
    cout << setprecision(2);
    cout << "Precision:" << cout.precision() << ".value:" << sqrt(2.0) << endl;
    cout << "=====================================================" << endl;

    // 输出多进制
    cout << showbase;
    cout << "default:" << 20 << "," << 1024 << endl;
    cout << "octal  :" << oct << 20 << "," << 1024 << endl;
    cout << "hex    :" << hex << 20 << "," << 1024 << endl;
    cout << "decimal:" << dec << 20 << "," << 1024 << endl;
    cout << noshowbase;
    cout << "=====================================================" << endl;

    // 读取空白字符
    // char ch;
    // cin >> noskipws;
    // while (cin >> ch)
    //     cout << ch;
    // cin >> skipws;
    // \033[<bg color>;<word color>m 注意最后要用\033[0m清除格式
    printf("\033[0;31m it is colorful! \033[0m\n");
    cout << "\033[0;32m" << setfill('#') << left << setw(12) << a << "next col" << endl
         << setw(12) << b << "next col" << endl
         << setw(12) << c << "next col" << endl
         << setfill(' ')
         << "\033[0m" << endl;
    cout << "=====================================================" << endl;
}