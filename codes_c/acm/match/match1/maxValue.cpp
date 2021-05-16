#include<iostream>

using namespace std;
int t,n,m,value;
int ans[10001];

int main()
{
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n>>m;
        if(n==1)ans[i]=0;
        else if(n==2)ans[i]=m;
        else ans[i]=2*m;
        
    }
    for(int k=0;k<t;k++) cout<<ans[k]<<endl;
    return 0;
}