#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<math.h>

using namespace std;
int n;
int a[1000001]={0};
int theBiggest=0;
int theAnswerNum,lastAnswerNum;

int main()
{
    int temp;
    scanf("%d",&n);
    for(int i=0;i<n;i++) 
        {
            scanf("%d",&temp);
            theBiggest = max(theBiggest,temp);
            a[temp]++;
        }
    for(int j=2;j<=theBiggest;j++)
    {
        theAnswerNum = 0;
        for(int k=0;k<=theBiggest;k+=j)
        {
            theAnswerNum +=a[k];
        }
        theAnswerNum = max(theAnswerNum,lastAnswerNum);
        lastAnswerNum = theAnswerNum;
    }
    cout<<theAnswerNum<<endl;

    return 0;
}