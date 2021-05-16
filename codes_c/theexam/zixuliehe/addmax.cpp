#include<iostream>

using namespace std;
int n,A[1001];
int dp[10001];

void myInit()
{
    cin>>n;
    for(int i=0;i<n;i++) cin>>A[i];
    dp[0]=A[0];
}

int myMax(int a,int b)
{
    if(a>b) return a;
    else return b;
}

void solveDP()
{
    for(int i=1;i<n;i++)
        {dp[i]=myMax(A[i],dp[i-1]+A[i]);
        //cout<<"dp["<<i<<"]"<<"="<<dp[i]<<" ";
        }
}

int findMax()
{
    int res=dp[0];
    for(int i=1;i<n;i++)
        res=myMax(res,dp[i]);
    return res;
}

int main()
{
    myInit();
    if(n!=1){solveDP();
    cout<<findMax()<<endl;}
    else cout<<A[0]<<endl;
    return 0;
}