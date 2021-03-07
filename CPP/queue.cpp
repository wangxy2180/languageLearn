#include <iostream>
#include <queue>

using namespace std;
// queue,队列，只能在末尾添加新数据，在头部添加元素；
int main()
{
    queue<int> que;
    for (int i = 0; i < 5; i++)
        que.push(i);
    for (int i = 0; i < 2; i++)
    {
        cout << que.front() << endl;
        que.pop();
        cout << que.back() << endl;
    }
}