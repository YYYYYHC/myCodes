#include<stdio.h>
int main()
{
    int x,y; //xy就是输入的两个数
    int m,n,z; //不用管
    scanf("%d%d",&x,&y);
    m=x,n=y;
    while(y)
    {
        z = x%y;
        x = y;
        y = z;
    }
//这两行输出留一个就行
    printf("最大公约数：%d\n",x);
    printf("最小公倍数：%d\n",m*n/x);
    return 0;
}