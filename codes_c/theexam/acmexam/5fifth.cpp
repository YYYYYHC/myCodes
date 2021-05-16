#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>

using namespace std;
long long n,m;
long long A[1000000];
long long sum=0;
long long  big;
 int mem1=0;
    int mem2=0;

void myInit()
{
    cin>>n>>m;
    for(long long  i=0;i<n;i++) cin>>A[i];
    return;
}

void solvePro()
{
   
    for(long long i=0;i<n;i++) sum+=A[i];

    big =A[0];
    int secbig =A[0];

    for(long long i=0;i<n;i++) 
    {
        if(big<A[i]){
            big=A[i];
            mem1=i;
        }
        else if(secbig<A[i])
        {
            secbig=A[i];
            mem2=i;
        }
    }
  //  cout<<big<<endl;
    
    
    cout<<sum-(n>big?n:big)+A[mem1]-A[mem2];
    return;
}

int main()
{
    myInit();
    solvePro();
    return 0;
}