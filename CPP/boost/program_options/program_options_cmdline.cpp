#include <boost/program_options.hpp>
#include <iostream>
using namespace std;

namespace po = boost::program_options;

int main(int argc, char **argv)
{
    // 设置一些变量，用来存放从desc获取的值
    int apple_num = 0, orange_num = 0;
    vector<string> addr;

    po::options_description desc("options descrcption");

    desc.add_options()
        // 设置默认值,也就是你不管输不输，他count都会为1
        ("apple,a", po::value<int>(&apple_num)->default_value(12), "the number of apple")
        ("orange,o", po::value<int>(&orange_num)->default_value(13), "the number of orange")
        // 生产地的数据类型是vector，可存放多个值,multitoken的作用就是告诉课接受多个值
        ("address", po::value<vector<string>>()->multitoken(), "生产地")
        ("help,h", "计算苹果和橘子的总数量");

    po::variables_map vm;
    try
    {
        po::store(po::parse_command_line(argc, argv, desc), vm);
    }
    catch (...)
    {
        std::cerr << "未定义的标识符" << '\n';
    }

// 参数解析完成后，通知variables_map更新所有外部变量
// 执行这句话apple和orange更新为指定的值
// 其实这里是有疑问的，为啥demo里没有，也能正常运行呢
    po::notify(vm);

    if (vm.count("help"))
        cout << desc << endl;
    if (vm.count("address"))
        for (auto k : vm["address"].as<vector<string>>())
            cout << "address: " << k << endl;
    if (vm.empty())
        cout << "no options found" << endl;
    
    cout<<"the num of apple:  "<<apple_num<<endl;
    cout<<"the num of orange: "<<orange_num<<endl;
    cout<<"the num of two :   "<<apple_num+orange_num<<endl;
}