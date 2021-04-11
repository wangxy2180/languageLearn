#include <iostream>

class Fraction
{
public:
    Fraction(int num, int den = 1) : m_numerator(num), m_denominator(den) {}
    operator double() const
    {
        // 这里和视频里的有差异，视频里直接对除完的进行double转换，但是他的好像不太对
        return (double)((double)m_numerator / m_denominator);
    }

private:
    int m_numerator;   //分子
    int m_denominator; //分母
};

using namespace std;

int main()
{
    Fraction f(3, 5);
    double ret = 4.2 + f;
    cout << ret;
}