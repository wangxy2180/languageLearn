#include <iostream>

// explicit 几乎只在构造函数前边使用，另外就是模板的一个很细微的地方用到，也不谈了

class Fraction_1
{
public:
    // 现在这个构造函数，是two parameters，但是是one argument，只要一个实参就够了
    // non-explict-one-argument ctor
    Fraction_1(int num, int den = 1) : m_numerator(num), m_denominator(den) {}
    Fraction_1 operator+(const Fraction_1 &f)
    {
        // 这是错误的加法！只是为了解释语法
        return Fraction_1(m_numerator + f.m_numerator, m_denominator + f.m_denominator);
    }

private:
    int m_numerator;   //分子
    int m_denominator; //分母
};

class Fraction_2
{
public:
    // 现在这个构造函数，是two parameters，但是是one argument，只要一个实参就够了
    // explict-one-argument ctor
    // 加上explicit就是告诉编译器，你不能再替我做隐式转换了，不能私自把3变为3/1
    explicit Fraction_2(int num, int den = 1) : m_numerator(num), m_denominator(den) {}
    Fraction_2 operator+(const Fraction_2 &f)
    {
        // 这是错误的加法！只是为了解释语法
        return Fraction_2(m_numerator + f.m_numerator, m_denominator + f.m_denominator);
    }
    operator double() const
    {
        return ((double)m_numerator / m_denominator);
    }

private:
    int m_numerator;   //分子
    int m_denominator; //分母
};

using namespace std;

int main()
{
    Fraction_1 f(3, 5);

    // 因为我的operator+设计的是两个分数相加
    // 这里是通过non-explicit ctor将4转换为Fraction(4,1),然后调用operator +
    // 也就是说，因为Fraction的构造函数可以只接受一个实参，所以他隐式转换了
    Fraction_1 ret = f + 4;
    // 如果这个类里定义了一个operator double(),那编译器会发现有两条路线可行，编译器就会报错，出现二义性
    // 他可以把f转为double，然后ret再转为Fraction；也可以4转为Fraction，然后ret转为double，怎么写都会有问题

    Fraction_2 f_2(3,4);
    // 下边这条语句会报错，因为他不会自动的隐式把4转换为4/1
    // Fraction_2 ret_2=f_2+4;
    // 但是可以将Fraction转为double
    double ret_2=4+f_2;
    cout<<ret_2<<endl;
}