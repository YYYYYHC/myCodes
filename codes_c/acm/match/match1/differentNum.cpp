#include<iostream>
#include<algorithm>

using namespace std;

long long n;
long double A[10000000];

int main()
{
    cin>>n;
    for(long long i=0;i<n;i++) cin>>A[i];
    sort(A,A+n);
    // for(long long i=0;i<n;i++) cout<<A[i];
    long long cnt=1;
    for(long long j=1;j<n;j++)
    {
        if(A[j]-A[j-1]==0)
        {
            continue;
            // if(j==n-1) cnt=cnt;
        }
        cnt++;        
    }
    cout<<cnt;
    return 0;
}
