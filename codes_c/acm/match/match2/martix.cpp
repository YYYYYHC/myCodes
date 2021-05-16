#include <iostream>
#include <stdio.h>

using namespace std;
long m,n;
int q,qmode,qx,qy,qz;
int martix[1000001];
int haha[1000001];

void myInput()
{
    scanf("%ld%ld",&m,&n);
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
        scanf("%d",&martix[(i-1)*n+j]);
}

int main()
{
    myInput();
    scanf("%d",&q);
    int flag=0;
    for(int k=0;k<q;k++)
        {
            scanf("%d%d%d",&qmode,&qx,&qy);
            if(qmode==1)
            {
                scanf("%d",&qz);
                martix[(qx-1)*n+qy]=qz;
            }
            else
            {
                haha[flag++]=martix[(qx-1)*n+qy];
            }
        }
    for(int t=0;t<flag;t++)
        printf("%d\n",haha[t]);
    return 0;
}