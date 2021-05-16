#include<stdio.h>

int A[100],B[100],C[100];

void Array_del(int n,int pos)
{
    for(int i=pos;i<n-1;i++)
    {
        A[i]=A[i+1];
    }
}

int main()
{
    int m,n,p;
    
    scanf("%d%d%d",&m,&n,&p);
    for(int i = 0; i<m;i++)
        scanf("%d",&A[i]);
    for(int i = 0; i<n;i++)
        scanf("%d",&B[i]);
    for(int i = 0; i<p;i++)
        scanf("%d",&C[i]);
    
    //寻找BC中的相同数
    int ta=0,tb=0,tc=0;
    while(tb!=n&&tc!=p)
    {
        if(B[tb]<C[tc])
        {
            tb++;
        }
        else if(B[tb]>C[tc])
        {
            tc++;
        }
        else
        {
            while(ta<=m&&A[ta]<B[tb]) ta++;
            if(A[ta]==B[tb]) 
            {
                Array_del(m,ta);
                m--;
            }
            tb++;
            tc++;
        }
    }
    
for(int i=0;i<m;i++)
    printf("%d ",A[i]);
    return 0;
}