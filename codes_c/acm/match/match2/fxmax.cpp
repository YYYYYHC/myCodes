#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<math.h>

using namespace std;
int n;
int a[1000000];
int theBiggest;
int theAnswerNum,lastAnswerNum;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    theBiggest = *max_element(a,a+n);

    for(int j=2;j<=theBiggest;j++)
    {
        theAnswerNum = 0;
        for(int k=0;k<n;k++)
        {
            if(a[k]%j==0) theAnswerNum++;
        }
        theAnswerNum = max(theAnswerNum,lastAnswerNum);
        lastAnswerNum = theAnswerNum;
    }
    cout<<theAnswerNum<<endl;

    return 0;
}