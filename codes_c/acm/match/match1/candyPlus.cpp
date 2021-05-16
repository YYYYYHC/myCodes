#include<iostream>

using namespace std;
int n,t;
long long  candies[100002];
int L,R;
long long  ans[100002];
// int flag[100001]={1};

void solve()
{
    ans[0]=candies[0];
    for(int i=1;i<n;i++) ans[i]=candies[i]-candies[i-1];
}

int main()
{
    cin>>n;
    int i;
    long long b;
    for( i=0;i<n;i++) cin>>candies[i];
    solve();
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>L>>R>>b;
        ans[L-1]-=b;
        ans[R]+=b;
        // if(ans[L-1]<0)
        // {
        //     ans[L-1] = -ans[L-1];
        //     // flag[L-1] = -flag[L-1];
        // }
        //   if(ans[R]<0)
        // {
        //     ans[R] = -ans[R];
        //     // flag[R] = -flag[R];
        // }
        
       
    }
    long long temp=0;
    for(i=0;i<=n-1;i++)
    {
        temp+=ans[i];
        cout<<temp<<' ';
    }

    return 0;
}