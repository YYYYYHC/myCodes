#include<iostream>

using namespace std;
int n,c;
int weights[1001];
int dp[1005][1005];

void myInit()
{
    cin>>n>>c;
    for(int i=0;i<n;i++) cin>>weights[i];
    for(int j=2;j<n+2;j++) dp[j][0]=weights[j-2];
    for(int k=2;k<c+2;k++) dp[0][k]=k-1;
}

int myMax(int a, int b)
{
    return a>b?a:b;
}

void solveDP()
{
    for(int i=2;i<n+2;i++)
        for(int j=2;j<c+2;j++)
        {
            if(dp[i][0]<=dp[0][j]-dp[i-1][j]) dp[i][j]=dp[i-1][j]+dp[i][0];
            else if(dp[i][0]>dp[0][j]) dp[i][j]=dp[i-1][j];
            else dp[i][j]=myMax(dp[i-1][j],dp[i-1][j-dp[i][0]]+dp[i][0]);
        }
}

int main()
{
    myInit();
    solveDP();
    cout<<dp[n+1][c+1]<<endl;
    return 0;
}