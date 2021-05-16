#include<iostream>

using namespace std;
int n,t;
int candies[100001];
int L,R;
long long ans[100001];

int main()
{
    cin>>n;
    int i;
    ans[0]=0;
    for( i=0;i<n;i++) 
    {
        cin>>candies[i];
        ans[i+1]=ans[i]+candies[i];
    }
    cin>>t;
    long long test[100001];
    for(i=0;i<t;i++)
    {
        cin>>L>>R;
        test[i] = ans[R]-ans[L-1];
    }
    for( i=0;i<t;i++) cout<<test[i]<<endl;

    return 0;
}