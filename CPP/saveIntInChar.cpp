#include <stdio.h>

#define INT_SIZE 4
#define BUF_SIZE 12

int main()
{
    int a = 0;
    char ch[BUF_SIZE];
    for (int i = 0; i < BUF_SIZE / INT_SIZE; ++i)
    {
        scanf("%d", (int *)&ch[i * INT_SIZE]);
    }
    // 这里要注意一件事，10000000 是 -128，复习一下反码与补码的知识
    for (int i = 0; i < BUF_SIZE; ++i)
    {
        printf("ch %d is : %d\n", i, ch[i]);
    }
    printf("----------------\n");

    int *aa = (int *)ch;
    for (int i = 0; i < BUF_SIZE / INT_SIZE; ++i)
    {
        printf("int %d is : %d\n", i, *aa);
        aa++;
    }
}