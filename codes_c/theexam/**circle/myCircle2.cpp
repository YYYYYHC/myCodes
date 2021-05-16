#include<iostream>
#include<math.h>

using namespace std;
int A[21];
int used[21];

bool judge(int num)
{
    for(int i=2;i<=sqrt(num);i++)
        if(num%i==0) return 0;
    return 1;
}

bool dfs(int pos)
{
    if(pos==21&&judge(A[1]+A[20])) return true;
    else
    {
        for(int i=1;i<=20;i++)
        {
            if(used[i]==0 && judge(i+A[pos-1]))
            {
                A[pos]=i;
                used[i]=1;
                if(dfs(pos+1)) return true;
                used[i]=0;

            }
        }
        return false;
    }

}

int main()
{
    dfs(1);
    for(int i=1;i<=19;i++) cout<<A[i]<<" ";
    cout<<A[20];
    cout<<endl;
    return 0;
}