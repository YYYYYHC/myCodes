#include<stdio.h>

void output(int A[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        printf("%d ",A[i]);
    }
    printf("%d",A[n-1]);
}

int main()
{
    int theSeqList[100000];
    int elenum = 0;
    int theInputNum=0;

    scanf("%d",&elenum);

    for(int j=0;j<elenum;j++)
    {
        scanf("%d",&theSeqList[j]);
    }

    scanf("%d",&theInputNum);

    int k=0;
    while(theInputNum >= theSeqList[k] && k<elenum)
    {
        k++;
    }

    // if(theSeqList[k] == theInputNum) 
    //     output(theSeqList,elenum);
    // else{
        for(int l=elenum-1;l>=k;l--)
        {
            theSeqList[l+1] = theSeqList[l];
        }
        theSeqList[k] = theInputNum;
        output(theSeqList,elenum+1);
    // }
    return 0;
}