#include <iostream>
#include <vector>
#include <deque>

using namespace std;

const int WINDOW_SIZE = 3;
const int MAX_DIST = 6;

struct xy_event
{
    int x;
    int y;
};

vector<xy_event> remove_pixel_ret(vector<xy_event> &input)
{
    int len = input.size();

    vector<xy_event> ret(len, {-1, -1});
    int ret_tail = 0;

    // 每一行的左、右两端
    int line_l = 0, line_r = 0;
    while (line_r < len)
    {
        // 遍历数据，把同一行的提取出来
        while (input[line_l].x == input[line_r].x)
        {
            line_r++;
        }
        // 当前行甚至连三个都没有，你就直接噪点吧
        if (line_r - line_l < WINDOW_SIZE)
        {
            line_l = line_r;
            continue;
        }
        // 如果是连续的，那就只对left+WINDOW_SIZE进行赋值，否则就对窗口内所有进行赋值
        bool is_last = false;
        // bool is_cont = false;

        // 遍历line_l到line_r，对单行进行检测
        for (int left = line_l; left < line_r; ++left)
        {
            // 范围是[6,+inf]
            if (input[left + WINDOW_SIZE - 1].y - input[left].y >= MAX_DIST)
            {
                // 左右两端的距离超出了最大距离，窗口直接向右移动,并且连续性断开了
                is_last = false;
                continue;
            }
            else
            {
                // 下边这个if里才是最正常的状态，其实这里应该吧WINDOW_SIZE里的全都弄上
                if (line_r - left >= WINDOW_SIZE)
                {
                    // 并且是连续的，也就是只对最后一个赋值
                    if (is_last)
                    {
                        ret[ret_tail] = input[left + WINDOW_SIZE - 1];
                        ret_tail++;
                        is_last = true;
                    }
                    // 不连续
                    else
                    {
                        // 是这个前进步数惹得锅，left不要向前
                        for (int i = 0; i < WINDOW_SIZE; ++i)
                        {
                            ret[ret_tail] = input[left + i];
                            ret_tail++;
                            is_last = true;
                        }
                    }
                }
                // 余下的不足一个WINDOW_SIZE了，特殊处理一下
                else
                {
                    // 刚刚那个是有效的
                    if (ret[ret_tail].y == input[left].y)
                    {
                        while (left < line_r)
                        {
                            ret[ret_tail] = input[left];
                            ret_tail++;
                            left++;
                        }
                    }
                }
            } //end if
        }     //end for

        // line_l转到下一行
        {
            line_l = line_r;
        }
    }

    return ret;
}

vector<xy_event> remove_pixel_ret2(vector<xy_event> &input)
{
    int len = input.size();

    vector<xy_event> ret(len, {-1, -1});
    int ret_tail = 0;

    // 每一行的左、右两端
    int line_l = 0, line_r = 0;
    while (line_r < len)
    {
        // 遍历数据，把同一行的提取出来
        while (input[line_l].x == input[line_r].x)
        {
            line_r++;
        }
        // 当前行甚至连三个都没有，你就直接噪点吧 （<3）
        if (line_r - line_l < WINDOW_SIZE)
        {
            line_l = line_r;
            continue;
        }
        // 如果是连续的，那就只对left+WINDOW_SIZE进行赋值，否则就对窗口内所有进行赋值
        bool is_last = false;
        // bool is_cont = false;

        // 遍历line_l到line_r，对单行进行检测
        for (int left = line_l; left < line_r; ++left)
        {
            // 不需要考虑边界的情况  应该该行剩下的还足够WINDOW_SIZE，至少有4个 （>3），这里似乎可以改为>=
            if (line_r - left >= WINDOW_SIZE)
            {
                // 范围是[6,+inf) 不满足条件
                if (input[left + WINDOW_SIZE - 1].y - input[left].y >= MAX_DIST)
                {
                    // 左右两端的距离超出了最大距离，窗口直接向右移动,并且连续性断开了
                    is_last = false;
                    continue;
                }
                // 范围是[1-5] 满足条件
                else
                {
                    // 上一个窗口是满足条件的，也就是说当前这个出现了，他依然是满足的，将右边最新的更新进去
                    if (is_last)
                    {
                        ret[ret_tail] = input[left + WINDOW_SIZE - 1];
                        ret_tail++;
                        is_last = true;
                    }
                    // 上一窗口不满足条件，加上现在这个，他满足条件了
                    else
                    {
                        // 是这个前进步数惹得锅，left不要向前
                        for (int i = 0; i < WINDOW_SIZE; ++i)
                        {
                            ret[ret_tail] = input[left + i];
                            ret_tail++;
                            is_last = true;
                        }
                    }
                }
            }
            // 考虑边界的情况 （=2）
            else
            {
                // 刚刚那个是有效的，假设最后是1239，那么123是有效的，239又是无效的
                if (is_last)
                {
                    // 似乎啥都不用做,直接让他到下一行就行，因为在上一步已经把满足的都加进去了
                    left+=2;
                }
                // 最后三个其实是不满足的，那也直接到最后就好了吧
                else
                {
                    left+=2;
                }
            }

        } //end for

        // line_l转到下一行
        {
            line_l = line_r;
        }
    }

    return ret;
}

void remove_pixel_in_place(vector<xy_event> &input)
{
    int len = input.size();

    // 每一行的左、右两端,while执行一次，处理一行
    int line_l = 0, line_r = 0;
    while (line_r < len)
    {
        // 遍历数据，找出本行的右边界
        while (input[line_l].x == input[line_r].x)
        {
            line_r++;
        }
        // 当前行甚至连三个都没有，你就直接噪点吧
        if (line_r - line_l < WINDOW_SIZE)
        {
            for (int i = line_l; i < line_r; ++i)
            {
                input[i].x = -1;
            }
            line_l = line_r;
            continue;
        }
        // 以上都没错

        // 如果是连续的，那就只对[left+WINDOW_SIZE-1]进行赋值，否则就对窗口内所有进行赋值
        bool is_last = false;

        // 遍历line_l到line_r，对单行进行检测
        for (int left = line_l; left < line_r; ++left)
        {
            // 应该该行剩下的还足够WINDOW_SIZE，至少有4个
            if (line_r - left > WINDOW_SIZE)
            {
                // 距离是[1,5]
                if (input[left + WINDOW_SIZE - 1].y - input[left].y < MAX_DIST)
                {
                    // 如果窗口左右的值小于最大距离，那么直接把窗口左边的位置向右移动一个，并且设置is_last为true
                    is_last = true;
                    continue;
                }
                // 距离是[6,+inf)
                else
                {
                    // 前边的满足条件，那么就是最新进来的导致不满足了，我直接让新进来的变为新窗口的第一个
                    if (is_last)
                    {
                        // 这里就不对了，万一后边他又接上了呢比如1,2,3,8,9,10.
                        // 238是不满足的，但是8不该被置为-1，
                        // 这个时候直接把left+1就可以吧，因为for那里还会再++
                        // 此时新的窗口就变味了8 9 10
                        // input[left + WINDOW_SIZE - 1].x = -1;
                        left += (WINDOW_SIZE - 2);
                        is_last = false;
                    }
                    // 上一个也不满足，那么最左边的肯定不满足了
                    else
                    {
                        // 只对第一个进行修改,然后窗口向右移动
                        input[left].x = -1;
                        is_last = false;
                    }
                }
            }
            // 要考虑边界的情况了，只剩三个了
            else
            {
                // 余下的刚好是最后一个WINDOW_SIZE了，需要特殊处理一下,left+WINDOW_SIZE就跑到下一行去了
                // cout << 1111111111111111 << endl;
                // 如果满足条件，那就什么都不用干，不满足条件，才要进一步处理
                if (input[left + WINDOW_SIZE - 1].y - input[left].y >= MAX_DIST)
                {
                    if (is_last)
                    {
                        input[left + WINDOW_SIZE - 1].x = -1;
                        is_last = false;
                    }
                    else
                    {
                        while (left < line_r)
                        {
                            input[left].x = -1;
                            left++;
                        }
                        is_last = false;
                    }
                }
                // 满足条件，直接下一行
                else
                {
                    left = line_r;
                }
                // line_l转到下一行
            }
        }
        {
            line_l = line_r;
        }
    }
}

int main()
{
    vector<xy_event> input1{{2, 53}, {2, 59}, {2, 65}, {2, 69}, {2, 75}, {2, 80}, {2, 84}, {2, 85}, {2, 101}, {2, 116}, {2, 669}};
    vector<xy_event> input2{{2, 67}, {2, 68}};
    vector<xy_event> input3{{3, 4}, {3, 6}, {3, 7}, {4, 1}, {4, 4}, {4, 5}, {4, 6}, {4, 7}, {4, 11}, {4, 14}};
    vector<xy_event> input4{{2, 67}, {2, 68}, {3, 11}, {3, 12}};
    vector<xy_event> input5{{1, 1}, {1, 2}, {1, 3}, {2, 8}, {2, 9}, {2, 10}, {8, 1}, {12, 1}, {12, 4}, {12, 9}, {12, 10}, {12, 11}, {12, 18}, {12, 19}, {12, 20}, {12, 21}, {12, 67}, {12, 68}, {12, 69}, {12, 100}};

    vector<xy_event> output;

    output = remove_pixel_ret2(input5);

    // output = input5;
    // remove_pixel_in_place(output);

    for (auto k : output)
    {
        cout << "(" << k.x << ", " << k.y << ")" << endl;
    }
}