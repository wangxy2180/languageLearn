#include <stdio.h>

int main()
{
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    int *ptr = (int*)(&a+1);
    printf("%d,%d\n",a[1],*(ptr-1));

    printf("addr of a   is %d\naddr of ptr is %d\n",a,ptr);

    printf("len is %d\n",(ptr-a));

    printf("sizeof a is:%d\n",sizeof(a)/sizeof(int));

    

}