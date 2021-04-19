// g++ program_options.cpp -lboost_program_options

#include <boost/program_options.hpp>
#include <iostream>
using namespace std;
namespace po = boost::program_options;

int main(int argc, const char *argv[])
{
    // 1. 构建选项描述器
    po::options_description desc("optionsss");
    // 选项存储容器
    po::variables_map vm;

    // 2.在描述器中增加选项
    // 这里的()有三个重载，分别是(key,value,描述) (key,描述) (key,value)
    // value的类型是value_semantic*
    // 同样可以有两种key的形式，逗号后的第一个字符为--filename或者-n，只使用逗号后的第一个字符,可以直接-filename=name或者-nname
    desc.add_options()
    ("filename,n", po::value<string>(), "file name of input file")
    ("filetype,t", po::value<string>(), "file type of input file")
    ("help,h", "just test program_options");

    // 3. 将输入的参数做解析，然后存入vm
    try
    {
        po::store(po::parse_command_line(argc, argv, desc), vm);
    }
    catch (...)
    {
        std::cerr << "未定义的选项！" << '\n';
        // return 0;
    }

    // 4.参数解析完毕，处理信息
    cout << vm.count("help") << "," << vm.count("filename") << "," << vm.count("filetype") << endl;
    // options_description支持流输出，会自动输出所有的选项
    // 通过[]取出来的元素，类型是boost::any，因此需要指定类型才能获取具体数值
    if (vm.count("help"))
        cout << desc << endl;
    if (vm.count("filename"))
        cout << "file name is: " << vm["filename"].as<string>() << endl;
    if (vm.count("filetype"))
        cout << "file type is: " << vm["filename"].as<string>() << endl;
    if (vm.empty())
        cout << "no options found" << endl;
}