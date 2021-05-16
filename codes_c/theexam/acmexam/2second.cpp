#include<iostream>

using namespace std;
int  n,k;
long long A[1000001];
long long dp[1000001];
long long pass;

void myInit()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)cin>>A[i];
    for(int i=0;i<n;i++) pass+=A[i];
}

int myMax(int a,int b)
{
    if(a>b) return a;
    else return b;
}

int solveDP()
{
    long long ans=0;
    long long mem=0;
    long long left,right;
    long long delta;
    for(int i=0;i<=k;i++)
       { 
        if(i==0)
        {
            for(int j=0;j<n-k;j++)
        {
            ans+=A[i+j]; 
            cout<<"ans1="<<ans<<endl;   
        }
            left=A[0];
            right=A[n-k-1];
        }
        else
        {
            delta+=A[i+n-k-1]-A[i-n+k];
            if(delta<0)
            {
                ans=0;
                for(int j=0;j<n-k;j++)
            {
               ans+=A[i+j];    
            }
            }

        }
       }
       return ans;
}


int main()
{
    int thesum=0;
    myInit();
    cout<<pass-solveDP();
    return 0;
}