#include<stdio.h>
#include<iostream>

using namespace std;
char A[200],B[200];
int lenA,lenB;
int dp[300][300];

void myInit()
{
    scanf("%s",A);
    lenA=strlen(A);
    scanf("%s",B);
    lenB=strlen(B);
    for(int i=2;i<lenA+2;i++) dp[i][0]=A[i-2];
    for(int j=2;j<lenB+2;j++) dp[0][j]=B[j-2];

}

int myMax(int a,int b)
{
    return a>b?a:b;
}

void solveDP()
{
    for(int i=2;i<lenA+2;i++)
        for(int j=2;j<lenB+2;j++)
        {
            if(dp[i][0]==dp[0][j]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=myMax(dp[i-1][j],dp[i][j-1]);
        }
}

int main()
{
    myInit();
    solveDP();
    cout<<dp[lenA+1][lenB+1]<<endl;
    return 0;
}