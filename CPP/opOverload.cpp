#include <iostream>

class MyDS
{
private:
    int part_1, part_2;

public:
    // 构造函数也可以传引用
    MyDS(int part_1 = 0, int part_2 = 0) : part_1(part_1), part_2(part_2){};

    std::string get_value()
    {
        return std::to_string(part_1) + ".." + std::to_string(part_2);
    }

    int get_part_1() const
    {
        return part_1;
    }

    int get_part_2() const
    {
        return part_2;
    }

    // 这里的返回类型最好还是这么写，因为可能有人这么写
    // c3+=c2+=c1,
    // 成员函数的操作符重载
    inline MyDS &operator+=(const MyDS &r)
    {
        // 为什么这里要多调用一次呢？因为其他地方可能会用到，独立出来
        return __doapl(this, r);

        // 谁调用这个函数，谁就是this，这里左值就是th
    }

    inline MyDS &
    __doapl(MyDS *ths, const MyDS &r)
    {
        ths->part_1 += r.part_1;
        ths->part_2 += r.part_2;
        return *ths;
        // 你返回的是value
        // 传递者无需知道接收者是以reference形式接收,
        // ths返回的是一个东西（object），但是接收端怎么接收你不用管。也许是用值接收，也许是引用接收
    }
};

// 非成员函数的操作符重载,当然可以根据不同的写法写多个
// 注意，这个返回的不能是reference！必须返回object，因为生命周期只在函数内部
inline MyDS
operator+(const MyDS &a, const MyDS &b)
{
    // 这是一个临时对象
    return MyDS(a.get_part_1() + b.get_part_1(), a.get_part_2() + b.get_part_2());
}

// 下边这个操作符一定不要！！写为成员函数，只能写成全局的
// 这两个参数就是使用者使用时的左边和右边，
// 第一个参数就是cout，他是一个对象
// 当然你也可以让他的返回值是void，但是为了能够连串的输出，最好还是有返回，也就是返回还要是cout这种东西
// <<输出是从左向右输出，而非从右向左聚集再输出
// 因为os不是local的，所以可以返回引用
inline std::ostream &
operator<<(std::ostream &os, const MyDS &x)
{
    return os << "MyDS value is:" << x.get_part_1() << ".." << x.get_part_2() << std::endl;
}

int main()
{
    MyDS a(1, 2);
    MyDS b(3, 4);
    a += b;
    std::cout << a.get_value() << std::endl;
    std::cout << "-------------" << std::endl;

    // 下边的例子可以说为为什么+=函数的返回值不能是空，‘=’右边是一整个函数 如果你把他改成返回值空，那么会报错
    MyDS c;
    c = a += b;
    std::cout << c.get_value() << std::endl;
    std::cout << "-------------" << std::endl;

    MyDS d;
    d = a + b;
    std::cout << d.get_value() << std::endl;
    std::cout << "-------------" << std::endl;
    std::cout << d;
}