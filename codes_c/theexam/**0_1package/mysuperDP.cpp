#include<iostream>

using namespace std;
int n,c;
int weights[11];
int value[11];
int dp[14][14];


void myInit()
{
    cin>>n>>c;
    for(int i=0;i<n;i++) cin>>weights[i];
    for(int j=0;j<n;j++) cin>>value[j];
    for(int k=2;k<n+2;k++) dp[k][0]=weights[k-2];
    for(int p=2;p<c+2;p++) dp[0][p]=p-1;
}

int myMax(int a,int b)
{
    return a>b?a:b;
}

void solveDP()
{
    for(int i=2;i<n+2;i++)
        for(int j=2;j<c+2;j++)
        {
            if(dp[i][0]>dp[0][j]) dp[i][j]=dp[i-1][j];
            else if(dp[i][0]<=dp[0][j]-dp[i-1][j]) dp[i][j]=dp[i-1][j]+value[i-2];
            else
            {
                dp[i][j]=myMax(dp[i-1][j],value[i-2]+dp[i-1][j-dp[i][0]]);
            }
        }
}

int main()
{
    myInit();
    solveDP();
    cout<<dp[n+1][c+1]<<endl;
    return 0;
}