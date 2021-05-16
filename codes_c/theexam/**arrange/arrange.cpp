#include<iostream>
#include<stdio.h>

using namespace std;
int N,B[1001],E[1001];
int cnt=1;

void myInit()
{
    cin>>N;
    for(int i=0;i<N;i++) cin>>B[i]>>E[i];
}

void EndSort()
{
    for(int i=0;i<N-1;i++)
        for(int j=i+1;j<N;j++)
        {
            if(E[j]<E[i])
            {
                swap(E[i],E[j]);
                swap(B[i],B[j]);
            }
        }
}

void solvePro()
{
    int curEnd=E[0];
    for(int i=1;i<N;i++)
    {
        if(B[i]>=curEnd){
            cnt++;
            curEnd=E[i];
        }
    }
}

int main()
{
    myInit();
    EndSort();
    solvePro();
    cout<<cnt<<endl;
    return 0;
}