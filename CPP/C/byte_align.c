#include <stdio.h>

// 结构体对齐最宽的数据类型
typedef struct{
    char i;
    double j;
    int k;
}s1;

typedef struct{
    double i;
    char j;
    int k;
}s2;

int main()
{
    printf("sizeof s1:%d\nsizeof s2:%d\n",sizeof(s1),sizeof(s2));
    // 这两个大小是不一样的，s1:24 s2:16

    
    char a[7]={'1','2','3','4','5','6','7'};
    char *ptr = (char*)(&a+1);
    printf("addr of a   is %d\naddr of ptr is %d\n",a,ptr);
    printf("len is %d\n",(ptr-a));
    printf("%d",sizeof(a));

}
