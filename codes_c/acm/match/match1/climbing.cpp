#include<iostream>

using namespace std;
long n;
long double A[1000000];

int main()
{
    cin>>n;
    long cnt=1,temp=1;
    long cnt2=1, temp2=1;
    for(long i=0;i<n;i++) cin>>A[i];
    for(long j=1;j<n;j++)
    {
        if(A[j]-A[j-1]>0) 
        {
            temp++;
            cnt2 = cnt2>temp2 ? cnt2:temp2;
            temp2=1;
        }
        else if(A[j]-A[j-1]<0)
        {
            temp2++;
            cnt=cnt > temp ? cnt : temp;
            temp=1;
        }
        else 
        {
            temp2=1;
            temp=1;
        }
        cnt = cnt>temp?cnt:temp;
        cnt2 = cnt2>temp2?cnt2:temp2;
    }
    cout<<max(cnt,cnt2);
    return 0;
}