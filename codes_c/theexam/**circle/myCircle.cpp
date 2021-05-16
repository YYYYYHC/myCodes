#include<iostream>
#include<math.h>

using namespace std;
int A[21],used[21];

bool isPrime(int a)
{
    for(int i=2;i<=sqrt(a);i++)
        if(a%i==0) return false;
    return true;
}

bool DFS(int pos)
{
    if(pos==20&&isPrime(A[0]+A[19])) 
    {
        for(int i=0;i<=18;i++)
        cout<<A[i]<<' ';
        cout<<A[19]<<endl;
        return true;
    }
    else
    {
        for(int i=1;i<=20;i++)
        {
            if(used[i]==0 && isPrime(i+A[pos-1]))
            {
                A[pos]=i;
                used[i]=1;
                if(DFS(pos+1)) return true;
                used[i]=0;
            }
        }
    return false;
    }
}

int main()
{
    DFS(0);
    return 0;
}