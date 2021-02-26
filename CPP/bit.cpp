#include <iostream>
#include <vector>
#include <unordered_map>
#include <bitset>

using namespace std;

int main()
{
    int a = 1;
    a = a << 2;
    cout << a << endl;
    cout << (1 << 2) << endl;

    // 统计某个字符串中出现的字母
    vector<string> str = {"aboveyz", "abrodyz", "abslute", "absoryz", "actresz", "gaswxyz"};
    unordered_map<string, int> mp;

    for (auto words : str)
    {
        int mask = 0;
        for (auto word : words)
        {
            mask |= (1 << (word - 'a'));
        }
        mp[words] = mask;
    }

    for (auto k : mp)
    {
        // 使用bitset输出二进制数<输出位数>
        cout << k.first << "," << bitset<26>(k.second) << endl;
    }

    cout << 'd' - 'a' << endl;
}