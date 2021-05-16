#include<stdlib.h>
#include<stdio.h>

int main()
{
    int n,m;
    int A[300],B[300],C[400]; //AB为输入 C为输出

    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&A[i]);

    scanf("%d",&m);
    for(int j=0;j<m;j++) scanf("%d",&B[j]);

    int x=0,y=0;
    int z=0;
    while(!(y==m&&x==n)) //当两个指针都没到底时 循环
    {
        if(y==m||x<n&&A[x]<=B[y]) //B到底或者A小于B
        {
            C[z]=A[x];
            x++;
        }
        else if(x==n||y<m&&A[x]>=B[y])
        {
            C[z]=B[y];
            y++;
        }
        z++;
    }

    for(int s=0;s<z-1;s++)
    {
        printf("%d\n",C[s]);
    }
    printf("%d\n",C[z-1]);
    return 0;
}