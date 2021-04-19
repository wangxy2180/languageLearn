#include <cstdio>
#include <sstream>
// #include <ostream>
#include <iostream>
using namespace std;

int main()
{
    string message("messagemessage;");
    // output_stream是一个标准输出，也可以是标准输入或者标准错误
    // 使用这样的方法，可以让他一起输出
    FILE* output_stream(stdout);
    fprintf(output_stream, "%s\n", message.c_str());
    fprintf(output_stream, "%s\n", "message2");
    fprintf(output_stream, "%s\n", "message3");
    fflush(output_stream);

    fprintf(stdout, "%s\n", "messagestdout");

}