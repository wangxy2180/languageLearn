#include <iostream>
#include <vector>

using namespace std;

void quickSort(vector<int> &a, int left, int right)
{
    int tmp_left = left, tmp_right = right;
    int key = a[left];
    if (left >= right)
        return;

    while (left < right)
    {
        while (left < right && key <= a[right])
            right--;
        if (left < right)
        {
            a[left] = a[right];
        }
        while (left < right && key >= a[left])
            left++;
        if (left < right)
        {
            a[right] = a[left];
        }
        a[left] = key;
    }
    quickSort(a, tmp_left, left - 1);
    quickSort(a, left + 1, tmp_right);
}

int main()
{
    // vector<int> a = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    vector<int> a = {8, 9, 6, 7, 4, 5, 2, 3, 0, 1};
    int len = a.size();
    quickSort(a, 0, len - 1);
    for (auto k : a)
    {
        cout << k << ",";
    }
}
