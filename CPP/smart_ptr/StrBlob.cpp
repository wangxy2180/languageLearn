#include <iostream>
#include <initializer_list>
#include <vector>
#include <memory>

using namespace std;

class StrBlob
{
public:
    // 为了使自己的程序具有良好的可以执行，应该更多地使用size_type. size_t而非int, unsigned
    // size_type是string和vector的定义的类型，用于保存任意对象的长度
    typedef vector<string>::size_type size_type;

    // 两种构造函数，接受空构造和列表构造
    StrBlob() : data(make_shared<vector<string>>()){};
    StrBlob(initializer_list<string> ls) : data(make_shared<vector<string>>(ls)){};

    size_type size() const { return data->size(); }

    bool empty() const { return data->empty(); }

    // 元素增删
    void push_back(const string &str) { data->push_back(str); }
    void pop_back() {}

    // 元素访问
    string &front() {}
    string &back() {}

    ~StrBlob();

private:
    // 为了保证vector中的数据一直存在，我们需要把他放在动态内存中
    shared_ptr<vector<string>> data;
    void check(size_type i, const string &msg) const
    {
        if (i >= data->size())
            throw out_of_range(msg);
    }
};
